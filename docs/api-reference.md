# Firebase Data Schema Reference — Smart PDS

This document describes the Firebase Realtime Database schema used by the Smart PDS platform. All three web portals (Authority, Customer, Shop Owner) and the ESP32 firmware interact with this shared database.

---

## Database Root Structure

```
smart-pds-db/
├── shops/                  # All registered Fair Price Shops
├── customers/              # Beneficiary records
├── transactions/           # Dispensing transaction logs
├── queue/                  # Live queue management
├── inventory/              # Stock levels per shop
└── system/                 # Global system configuration
```

---

## `/shops/{shopId}`

Each registered Fair Price Shop (FPS) has an entry keyed by its unique `shopId`.

| Field             | Type     | Description                                   |
|-------------------|----------|-----------------------------------------------|
| `name`            | string   | Name of the Fair Price Shop                   |
| `ownerName`       | string   | Name of the shop owner                        |
| `location`        | object   | `{ lat: number, lng: number, address: string }` |
| `district`        | string   | District where the shop is located            |
| `status`          | string   | `"active"` \| `"inactive"` \| `"flagged"`     |
| `lastSync`        | number   | Unix timestamp of last ESP32 data sync        |
| `registeredDate`  | string   | ISO 8601 date of registration                 |
| `totalCustomers`  | number   | Count of registered beneficiaries             |

### Example
```json
{
  "name": "FPS Mangalore Central",
  "ownerName": "Ramesh Kumar",
  "location": {
    "lat": 12.9141,
    "lng": 74.8560,
    "address": "MG Road, Mangalore, Karnataka"
  },
  "district": "Dakshina Kannada",
  "status": "active",
  "lastSync": 1715100000000,
  "registeredDate": "2025-11-15",
  "totalCustomers": 342
}
```

---

## `/customers/{customerId}`

Beneficiary records linked to their ration card and assigned shop.

| Field             | Type     | Description                                   |
|-------------------|----------|-----------------------------------------------|
| `name`            | string   | Full name of the beneficiary                  |
| `rationCardNo`    | string   | Government-issued ration card number          |
| `cardType`        | string   | `"AAY"` \| `"PHH"` \| `"APL"` \| `"BPL"`     |
| `assignedShopId`  | string   | Reference to the FPS (`shopId`)               |
| `phone`           | string   | Mobile number for OTP/notifications           |
| `monthlyQuota`    | object   | Entitled quantities per commodity             |
| `consumed`        | object   | Quantities already dispensed this month       |
| `lastTransaction` | number   | Unix timestamp of the most recent transaction |

### `monthlyQuota` / `consumed` sub-schema
```json
{
  "rice": 5.0,
  "wheat": 5.0,
  "sugar": 1.0,
  "kerosene": 3.0
}
```

---

## `/transactions/{transactionId}`

Immutable log of every dispensing event, created by the ESP32 firmware.

| Field             | Type     | Description                                   |
|-------------------|----------|-----------------------------------------------|
| `shopId`          | string   | Which shop processed the transaction          |
| `customerId`      | string   | Which beneficiary received the goods          |
| `commodity`       | string   | `"rice"` \| `"wheat"` \| `"sugar"` \| `"kerosene"` |
| `requestedWeight` | number   | Weight requested by the customer (kg)         |
| `dispensedWeight`  | number   | Actual weight measured by the load cell (kg)  |
| `deviation`       | number   | Difference: `dispensedWeight - requestedWeight` |
| `timestamp`       | number   | Unix timestamp when dispensing completed      |
| `status`          | string   | `"success"` \| `"partial"` \| `"failed"`     |
| `firmwareVersion` | string   | ESP32 firmware version that processed this    |

### Example
```json
{
  "shopId": "shop_001",
  "customerId": "cust_1042",
  "commodity": "rice",
  "requestedWeight": 5.0,
  "dispensedWeight": 4.98,
  "deviation": -0.02,
  "timestamp": 1715100500000,
  "status": "success",
  "firmwareVersion": "v2.1.3"
}
```

---

## `/queue/{shopId}/entries/{entryId}`

Live queue management for each shop, supporting the digital slot booking system.

| Field             | Type     | Description                                   |
|-------------------|----------|-----------------------------------------------|
| `customerId`      | string   | Beneficiary in the queue                      |
| `customerName`    | string   | Display name for the queue board              |
| `tokenNumber`     | number   | Sequential token number for the day           |
| `status`          | string   | `"waiting"` \| `"serving"` \| `"completed"`  |
| `joinedAt`        | number   | Unix timestamp when they joined               |
| `servedAt`        | number   | Unix timestamp when serving started (nullable)|
| `completedAt`     | number   | Unix timestamp when completed (nullable)      |

### `/queue/{shopId}/meta`

| Field             | Type     | Description                                   |
|-------------------|----------|-----------------------------------------------|
| `currentToken`    | number   | Token currently being served                  |
| `nextToken`       | number   | Next token number to be assigned              |
| `totalWaiting`    | number   | Count of customers in `"waiting"` status      |
| `avgServeTime`    | number   | Average serving time in seconds               |

---

## `/inventory/{shopId}`

Real-time stock levels for each commodity at each shop.

| Field             | Type     | Description                                   |
|-------------------|----------|-----------------------------------------------|
| `rice`            | object   | `{ current: number, capacity: number, unit: "kg" }` |
| `wheat`           | object   | `{ current: number, capacity: number, unit: "kg" }` |
| `sugar`           | object   | `{ current: number, capacity: number, unit: "kg" }` |
| `kerosene`        | object   | `{ current: number, capacity: number, unit: "L" }`  |
| `lastRestocked`   | number   | Unix timestamp of last restocking event       |
| `restockAlert`    | boolean  | `true` if any commodity is below 20% capacity |

---

## `/system`

Global configuration and system health metadata.

| Field             | Type     | Description                                   |
|-------------------|----------|-----------------------------------------------|
| `version`         | string   | Current platform version                      |
| `maintenanceMode` | boolean  | If `true`, portals show maintenance notice    |
| `lastBackup`      | number   | Unix timestamp of last database backup        |
| `totalShops`      | number   | Aggregate count of registered shops           |
| `totalBeneficiaries` | number | Aggregate count of registered customers     |

---

## Firebase Security Rules (Summary)

```
rules_version = '2';
service cloud.firestore {
  match /databases/{database}/documents {
    // Customers can only read their own data
    match /customers/{customerId} {
      allow read: if request.auth.uid == customerId;
    }
    
    // Shop Owners can manage their assigned shop
    match /shops/{shopId} {
      allow read, write: if request.auth.token.role == 'shopOwner' 
                         && request.auth.token.shopId == shopId;
    }
    
    // Authorities have global read access
    match /{document=**} {
      allow read: if request.auth.token.role == 'authority';
    }
  }
}
```

> **Note:** The actual project uses Firebase Realtime Database rules (JSON format), not Firestore. The above is a simplified representation of the access control logic.

---

## Data Flow Diagram

```
Customer App/Portal                ESP32 Firmware               Firebase RTDB
       │                                │                           │
       ├── Join Queue ───────────────── │ ────── Write ──────────► │
       │                                │                           │
       │                                ├── Auth Customer ─Read──► │
       │                                │                           │
       │                                ├── Dispense ──────────────►│ (transaction)
       │                                │                           │
       │                                ├── Update Inventory ─────►│
       │                                │                           │
       ├── View Allocation ◄─────────── │ ◄───── Read ◄───────────│
       │                                │                           │
Authority Portal ◄──────────────────────────── Live Sync ◄─────────│
```

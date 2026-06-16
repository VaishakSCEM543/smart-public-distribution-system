# System Architecture – Smart PDS

Smart PDS follows a layered **cyber-physical architecture** that integrates embedded hardware, firmware, a cloud backend, and three web portals into a single tamper-proof pipeline.

---

## Overview

```
┌───────────────────────────────────────────────────────────────┐
│  Layer 4 — Web Interface         (Authority / Shop / Customer) │
├───────────────────────────────────────────────────────────────┤
│  Layer 3 — Cloud & Backend       (Firebase Realtime Database)  │
├───────────────────────────────────────────────────────────────┤
│  Layer 2 — Embedded Firmware     (ESP32 / Arduino C++)         │
├───────────────────────────────────────────────────────────────┤
│  Layer 1 — Hardware              (Sensors, Servo, LCD)         │
└───────────────────────────────────────────────────────────────┘
```

---

## 1️⃣ Hardware Layer

| Component              | Role                                                    |
|------------------------|---------------------------------------------------------|
| ESP32 Dev Board        | Central microcontroller — runs all firmware logic       |
| Load Cell + HX711      | Measures weight in real-time; drives closed-loop control|
| Servo Motor            | Opens/closes the grain outlet based on weight feedback  |
| IR Sensor              | Verifies physical grain flow (secondary validation)     |
| 16×2 LCD (I2C, 0x27)  | Displays status messages to the beneficiary             |
| 4×3 Matrix Keypad      | OTP entry and menu navigation input                     |

**Key Design Principle:** The servo does **not** use a timer. It responds to load-cell weight readings, making it physically impossible to cheat by manipulating flow speed.

---

## 2️⃣ Embedded Firmware Layer

The firmware is written in **C++ / Arduino IDE** and split into focused modules:

| Module              | File(s)                          | Responsibility                                       |
|---------------------|----------------------------------|------------------------------------------------------|
| Entry Point         | `esp32.ino`                      | `setup()` / `loop()` orchestration                  |
| WiFi Management     | `wifi_manager.cpp / .h`          | Connect, retry on drop, log status to Serial         |
| Display             | `display.cpp / .h`               | LCD messages, error display, status updates          |
| Weight Sensing      | `scale.cpp / .h`                 | HX711 init, averaging, tare, tolerance check         |
| Firebase Sync       | `firebase.cpp / .h`              | HTTP PUT to RTDB, error code handling                |
| Authentication      | `auth.cpp / .h`                  | OTP/QR verification against Firebase                |
| Configuration       | `config.h`                       | WiFi credentials & Firebase URL (gitignored)         |

**Firmware Loop Behavior:**
1. `ensureWiFi()` — Reconnect if connection dropped.
2. Every 10 seconds: read weight → build JSON → `sendToFirebase()`.
3. Display updated weight on LCD.

---

## 3️⃣ Cloud & Backend Layer

**Platform:** Firebase Realtime Database (RTDB)

| Collection        | Contents                                                 |
|-------------------|----------------------------------------------------------|
| `/shops`          | Registered Fair Price Shop metadata & status            |
| `/customers`      | Beneficiary records, ration card, monthly quota          |
| `/transactions`   | Immutable dispensing log (created by firmware)          |
| `/queue`          | Live queue state per shop (tokens, waiting count)        |
| `/inventory`      | Real-time stock levels per commodity per shop            |
| `/system`         | Global config, maintenance mode, version                |

**Access Control (Firebase Security Rules):**
- Beneficiaries: read-only access to their own customer record.
- Shop Owners: read/write access to their assigned shop's queue and inventory.
- Authorities: global read access across all collections.

---

## 4️⃣ Web Interface Layer

Three **role-based portals** built in vanilla HTML/CSS/JS, served via GitHub Pages:

| Portal          | Users              | Key Features                                                   |
|-----------------|--------------------|----------------------------------------------------------------|
| Authority       | Government admins  | Live shop monitoring, AI fraud analyst, CSV export, analytics  |
| Shop Owner      | FPS operators      | Queue management, inventory tracking, transaction history       |
| Customer        | Beneficiaries      | Quota view, slot booking, real-time stock status               |

---

## End-to-End Data Flow

```
Beneficiary        ESP32 Firmware                Firebase RTDB         Web Portal
    │                    │                              │                    │
    ├── Enter OTP ──────►│                              │                    │
    │                    ├── Auth lookup ──────────────►│                    │
    │                    │◄── Customer quota ───────────┤                    │
    │                    │                              │                    │
    │                    ├── Servo open                 │                    │
    │                    ├── Load cell polling          │                    │
    │                    ├── Target reached → servo close│                   │
    │                    ├── Write transaction ─────────►│                   │
    │                    ├── Update inventory ──────────►│                   │
    │                    │                              ├── Live sync ──────►│
    │◄── LCD confirm ────┤                              │                    │
```

---

## Security Considerations

- **No timer-based dispensing** — weight is the only stop condition.
- **HTTPS (TLS)** for all ESP32 → Firebase communication.
- **Config secrets** (`config.h`) are gitignored and never committed.
- **RBAC** enforced at database layer via Firebase Security Rules.
- **Audit trail** — every dispensing event creates an immutable transaction record.

# System Architecture – Smart PDS

Smart PDS follows a layered cyber-physical architecture integrating hardware, embedded firmware, cloud backend, and web interfaces.

---

## 1️⃣ Hardware Layer

- ESP32 microcontroller
- Load cell + HX711
- Servo-based dispensing mechanism
- IR verification sensor
- 16x2 LCD (I2C)
- Keypad for input

Responsible for physical control and measurement.

---

## 2️⃣ Embedded Firmware Layer

- Authentication handling
- Weight monitoring
- Closed-loop dispensing
- Firebase REST communication
- Fault detection and retry logic

Implemented using Arduino / C++.

---

## 3️⃣ Cloud & Backend Layer

- Firebase Realtime Database
- Transaction storage
- Beneficiary records
- Inventory tracking

Enables centralized monitoring and logging.

---

## 4️⃣ Web Interface Layer

- Customer Portal
- Shop Owner Portal
- Authority Portal

Provides role-based access and system transparency.

---

## Data Flow

User → ESP32 → Dispensing → Weight Verification → Firebase → Web Dashboard

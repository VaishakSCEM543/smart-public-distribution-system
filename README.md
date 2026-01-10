# Smart Public Distribution System (Smart PDS)

An **end-to-end IoT-based Public Distribution System** designed to ensure **transparent, secure, and accurate delivery of subsidized food grains**, addressing leakage, fraud, and inefficiencies in India’s traditional PDS.

---

## 📌 Problem Background

India’s Public Distribution System (PDS) plays a critical role in food security, yet it faces major challenges such as:

- Large-scale **leakage of subsidized grains**
- **Manual dependency** and human intervention
- Inaccurate ration delivery
- Long queues and authentication failures
- Lack of real-time transparency and accountability

These issues result in financial loss to the government and denial of rightful benefits to citizens.

---

## 💡 Proposed Solution

**Smart PDS** is a **cyber-physical system** that combines:

- Automated ration dispensing hardware  
- Secure user authentication  
- Cloud-based data logging  
- Role-based web interfaces  

to **technically prevent leakage**, rather than merely detecting it after occurrence.

---

## 🧠 System Overview

The system is built as a **four-layer architecture**:

### 1️⃣ Hardware Layer
- ESP32-based control unit
- Load cell with HX711 for precise weight measurement
- Servo-controlled dispensing mechanism
- IR sensor for dispense verification
- OLED display and keypad for user interaction

> Dispensing is **sensor-verified**, not time-based.

---

### 2️⃣ Embedded Firmware Layer
- Authentication validation (Biometric / OTP / QR)
- Entitlement checks
- Closed-loop dispensing control
- Offline transaction caching
- Fault and error handling

Developed using **Arduino / C++**.

---

### 3️⃣ Cloud & Backend Layer
- Firebase (Realtime Database / Firestore)
- Stores:
  - Beneficiary data
  - Transaction logs
  - Inventory status
- Enables real-time synchronization and auditability

---

### 4️⃣ Web Interface Layer (Role-Based)

The system includes **three dedicated web portals**:

- **Customer Portal**  
  For beneficiaries to view transaction confirmation and status.

- **Shop Owner Portal**  
  For ration shop operators to manage dispensing and inventory visibility.

- **Authority Portal**  
  For government authorities to monitor transactions, analytics, and alerts.

This separation ensures **accountability and transparency** across all stakeholders.

---

## 🛠️ Technologies Used

### Hardware
- ESP32  
- Load Cell + HX711  
- Servo Motor  
- IR Sensor  
- OLED Display  
- Keypad  

### Software & Tools
- Arduino IDE  
- Arduino / C++  
- Firebase (Realtime DB / Firestore)  
- HTML, CSS, JavaScript  

---

## 📂 Repository Structure
```text
smart-public-distribution-system/
├── docs/          # Project documentation
├── hardware/      # Components, wiring, prototype details
├── firmware/      # ESP32 firmware
├── web/           # Role-based web portals
├── backend/       # Backend structure and rules
├── demo/          # Screenshots and demo material
└── references/    # Research and SIH material


⚠️ Important:
- The **three backticks** start the code block
- The **three backticks** end the code block
- `text` is optional, but recommended for clean formatting

---

## ✅ WHAT THIS DOES

- ✔ Fixed-width font (code look)
- ✔ Preserves alignment (`├──`)
- ✔ Looks professional
- ✔ Exactly like terminal output
- ✔ Very common in good GitHub READMEs

---

## 🧠 WHY I ORIGINALLY GAVE IT AS TEXT

When writing READMEs:
- **Explanation sections** → normal text
- **Structures / commands / outputs** → code blocks

You just hadn’t wrapped it in a code block yet — that’s all.

---

## 🔧 FINAL STEP (SAVE IT)

After fixing README:

```powershell
git add README.md
git commit -m "Format repository structure as code block in README"
git push origin main


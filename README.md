# Smart Public Distribution System (Smart PDS)

An **end-to-end IoT-based Public Distribution System** designed to ensure
**transparent, secure, and accurate delivery of subsidized food grains**,
addressing leakage, fraud, and inefficiencies in India’s traditional PDS.

---

## 📌 Problem Background

India’s Public Distribution System (PDS) plays a critical role in food security,
yet it faces major challenges such as:

- Large-scale **leakage of subsidized grains**
- High **manual dependency** and human intervention
- Inaccurate ration delivery
- Long queues and authentication failures
- Lack of real-time transparency and accountability

These issues result in financial loss to the government and denial of rightful
benefits to deserving citizens.

---

## 💡 Proposed Solution

**Smart PDS** is a **cyber-physical system** that integrates:

- Automated ration dispensing hardware  
- Secure user authentication  
- Cloud-based data logging  
- Role-based web interfaces  

to **prevent leakage at the system level**, rather than detecting it after occurrence.

---

## 🧠 System Overview

The system follows a **four-layer architecture**:

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
- Entitlement verification
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

### 4️⃣ 🔐 Security & Data Encryption

Security and data protection are integral to the Smart PDS system.

- Sensitive beneficiary and transaction data is **encrypted using AES**
  before being stored in the Firebase Realtime Database.
- Encryption is handled at the **application layer**, ensuring that data
  is not stored in plain text in the cloud.
- All communication between devices, web portals, and backend services
  occurs over **secure HTTPS (TLS)** connections.
- Authentication mechanisms (OTP / credentials) prevent unauthorized access.
- **Role-based access control** ensures:
  - Beneficiaries access only their own data
  - Shop owners have limited operational privileges
  - Authorities have monitoring and audit-level access
- Backend access is governed using **Firebase security rules**.
- Sensitive keys and configuration details are excluded from the public repository.

This approach ensures **confidentiality, integrity, and controlled access**
to Public Distribution System (PDS) data.

---

### 5️⃣ Web Interface Layer (Role-Based)

The system includes **three dedicated web portals**:

- **Customer Portal**  
  Allows beneficiaries to view transaction confirmation and ration status.

- **Shop Owner Portal**  
  Enables ration shop operators to manage dispensing and monitor inventory.

- **Authority Portal**  
  Provides government authorities with analytics, monitoring, and audit tools.

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
- Firebase (Realtime Database / Firestore)  
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

---
```
## ⚙️ Feasibility & Impact

The Smart PDS system is designed with real-world deployment in mind.

- Built using **low-cost, widely available hardware**
- Scalable across multiple ration shops and regions
- Supports **offline operation** with cloud synchronization
- Minimizes manual intervention, reducing corruption and errors
- Improves **transparency, accountability, and trust** in public welfare systems

The system is practical, deployable, and aligned with
government digitization and e-governance initiatives.

---

## 🚀 Future Scope

- Advanced fraud detection using analytics and AI  
- Smart inventory forecasting and demand prediction  
- Mobile application integration for beneficiaries  
- District- and state-level deployment  
- Enhanced cryptographic key management  
- Integration with national identity and welfare platforms  

---

## 👥 Team & Credits

**Team Name:** UDBHAV  
**Event:** Smart India Hackathon (SIH)

**Team Members:**
- Vaishak D. Karkera  
- <Teammate Name 2>  
- <Teammate Name 3>  
- <Teammate Name 4>  

**Role:**  
System Design, Hardware Development, Firmware, Web Interfaces, and Backend Integration

---

## 📄 License

This project is intended for **academic and prototype purposes**.  
License details will be added in future releases.


# Smart Public Distribution System (Smart PDS)

[![Live Demo](https://img.shields.io/badge/Live_Demo-View_Portals-success?style=for-the-badge&logo=github)](https://vaishakscem543.github.io/smart-public-distribution-system/)
[![Firebase](https://img.shields.io/badge/Firebase-Realtime_Sync-FFCA28?style=for-the-badge&logo=firebase&logoColor=white)](https://firebase.google.com/)
[![AI](https://img.shields.io/badge/AI-Fraud_Analyst-blue?style=for-the-badge&logo=robot&logoColor=white)](https://x.ai)

India’s Public Distribution System (PDS) is one of the **largest food security networks in the world**, serving **over 800 million beneficiaries** every month. Even small inefficiencies lead to significant economic and social consequences. Government audits estimate that **20–30% of subsidized food grains** are lost annually due to diversion, pilferage, and manual inefficiencies.

**Smart PDS** proposes a **cyber-physical, vending-machine–based ration distribution system** that automates dispensing at fair price shops. Combined with a **Real-Time Web Dashboard powered by AI Fraud Detection**, it aims to eliminate leakage and improve transparency in public welfare distribution.

👉 **[Try the Live Web Portals Here!](https://vaishakscem543.github.io/smart-public-distribution-system/)**

---

## 🌟 Key Features (Web Portals v3.5)

The Smart PDS ecosystem includes three distinct role-based web portals, recently upgraded with live data synchronization and AI capabilities:

### 🛡️ Authority Portal (Admin Dashboard)
- **Real-Time Monitoring:** Live tracking of all registered shops with dynamic Firebase data sync.
- **AI Fraud Analyst:** An integrated AI chatbot (powered by Grok) that analyzes live shop data, detects anomalies, and generates risk assessment reports. *(Includes a smart demo-mode fallback).*
- **Dynamic Analytics & Charts:** Live visual representation of stock distribution, commodity breakdown, and prediction accuracy using Chart.js.
- **Alert Management System:** Automated warnings and critical alerts for stock discrepancies with resolution workflows.
- **Export & Reporting:** Generate and download comprehensive CSV audit logs, map data, and transaction reports.

### 👥 Customer Portal
- Beneficiary-facing portal to view monthly allocations.
- Digital queue system & slot booking.
- Real-time stock status tracking at local Fair Price Shops.

### 🏪 Shop Owner Portal
- FPS owner dashboard for inventory management.
- Transaction logging and daily operations management.
- Automated queue control.

---

## 🧠 System Architecture

<img width="817" height="518" alt="system-architecture" src="https://github.com/user-attachments/assets/daca8789-0c45-4339-847b-da3438277a95" />

The system follows a **four-layer architecture**:

### 1️⃣ Hardware Layer
- **ESP32-based** control unit.
- **Load cell with HX711** for precise weight measurement.
- Servo-controlled dispensing mechanism.
- IR sensor for dispense verification.
- OLED display and keypad for user interaction.
> *Dispensing is **sensor-verified**, not time-based.*

### 2️⃣ Embedded Firmware Layer (C++)
- Authentication validation (Biometric / OTP / QR).
- Entitlement verification & closed-loop dispensing control.
- Offline transaction caching and error handling.

### 3️⃣ Cloud & Backend Layer
- **Firebase Realtime Database & Firestore**.
- Secure storage of beneficiary data, transaction logs, and inventory status.
- Enables the real-time dynamic updates seen across all web portals.

### 4️⃣ Security & Data Encryption
- Sensitive data is **encrypted using AES** before cloud storage.
- **Role-based access control** ensures stakeholders only see relevant data.
- Secure HTTPS (TLS) connections and Firebase security rules.

---

## 📸 Portal Previews

**Authority Portal Control Center**
<img width="1918" height="917" alt="authoritycontrol" src="https://github.com/user-attachments/assets/1165c03a-8a6a-469d-a654-635e33f3d6f0" />

**Customer Booking & Inventory**
<img width="1902" height="910" alt="Screenshot 2026-01-11 024212" src="https://github.com/user-attachments/assets/3330c777-aae7-4b29-8107-86e115fff17a" /> 

**Shop Owner Management**
<img width="1900" height="903" alt="shopownerportal" src="https://github.com/user-attachments/assets/85deec62-0380-4dfc-ad39-8ea8366b3d7c" />

---

## 🛠️ Technologies Used

- **Web Stack:** HTML5, Vanilla JavaScript, Bootstrap 5, CSS3 Glassmorphism
- **Cloud & Database:** Firebase (Auth, Realtime Database)
- **AI & Analytics:** Grok API integration, Chart.js, Leaflet.js
- **Hardware:** ESP32, Load Cell, Servo, Arduino IDE / C++

---

## 🚀 Future Scope

- District- and state-level massive deployment tracking.
- Advanced predictive modeling for inventory forecasting and demand.
- Native mobile application integration for beneficiaries.
- Integration with national identity (Aadhaar) and welfare platforms.

---

## 👥 Team & Credits

**Team Name:** UDBHAV  
**Event:** Smart India Hackathon (SIH)

**Team Members:**
- Vaishak D Karkera  
- Ashwin Suresh  
- Neha Raj
- Preetham Krishna  

**Role:**  
System Design, Hardware Development, Firmware, Web Interfaces, and Backend Integration.
  
---

## 📄 License

This project is licensed under the **MIT License**.
See the [LICENSE](LICENSE) file for details.

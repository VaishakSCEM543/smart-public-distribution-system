# Hardware Components – Smart Public Distribution System

This document lists the hardware components used in the Smart PDS prototype along with their purpose in the system.

---

## 🔹 1. ESP32 Development Board
**Role:** Main control unit  
- Handles authentication logic  
- Controls dispensing mechanism  
- Reads sensor data  
- Connects to WiFi for cloud communication  
- Interfaces with LCD and keypad  

---

## 🔹 2. Load Cell (5kg / 10kg) + HX711 Amplifier
**Role:** Weight measurement and verification  
- Measures actual quantity dispensed  
- Enables sensor-verified distribution  
- Prevents over-dispensing and fraud  
- Provides feedback for closed-loop control  

---

## 🔹 3. Servo Motor
**Role:** Dispensing mechanism control  
- Controls the opening/closing of grain outlet  
- Operates based on target weight  
- Ensures automated distribution  

---

## 🔹 4. IR Sensor
**Role:** Dispense verification  
- Detects grain flow  
- Adds additional validation layer  
- Helps prevent mechanical malfunction  

---

## 🔹 5. 16x2 LCD Display (I2C)
**Role:** User interface  
- Displays authentication status  
- Shows selected category and quantity  
- Displays weight confirmation  
- Provides system messages  

---

## 🔹 6. 4x3 Matrix Keypad
**Role:** User input interface  
- Used for OTP entry  
- Category and quantity selection  
- Manual navigation  

---

## 🔹 7. Power Supply Module
**Role:** System power regulation  
- Supplies stable voltage to ESP32  
- Powers load cell and display  
- Ensures reliable operation  

---

## 🔹 8. Mechanical Grain Container & Outlet Assembly
**Role:** Physical dispensing unit  
- Stores ration material  
- Guides grain flow during dispensing  
- Designed to integrate with servo control  

---

# ⚙️ System Hardware Architecture Overview

The Smart PDS hardware functions as a closed-loop dispensing system:

User Input → ESP32 → Servo Control → Grain Dispensing  
                         ↓  
                    Load Cell Feedback  
                         ↓  
                   Cloud Logging (WiFi)

The load cell continuously monitors the weight to ensure the exact entitled quantity is delivered.

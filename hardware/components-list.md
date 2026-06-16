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

---

# 🔌 ESP32 Wiring & Pin Reference

The table below documents the exact GPIO connections used in the Smart PDS prototype. Use this when assembling the hardware or debugging signal issues.

## Load Cell / HX711

| HX711 Pin | ESP32 GPIO | Notes                          |
|-----------|-----------|--------------------------------|
| VCC       | 3.3V      | Use 3.3V rail, not 5V          |
| GND       | GND       | Common ground                  |
| DT (DOUT) | GPIO 32   | Data out to ESP32              |
| SCK       | GPIO 33   | Clock signal from ESP32        |

> Calibration factor is `2280.0` — adjust via `scale.set_scale()` for your specific load cell.

---

## Servo Motor

| Servo Pin | ESP32 GPIO | Notes                                |
|-----------|-----------|--------------------------------------|
| Signal    | GPIO 13   | PWM output (use `Servo.h` library)   |
| VCC       | 5V (Vin)  | Servo needs 5V — use Vin not 3.3V    |
| GND       | GND       | Common ground                        |

---

## 16×2 LCD Display (I2C, PCF8574 backpack)

| LCD Pin | ESP32 GPIO | Notes                                  |
|---------|-----------|----------------------------------------|
| SDA     | GPIO 21   | I2C data line                          |
| SCL     | GPIO 22   | I2C clock line                         |
| VCC     | 5V (Vin)  | LCD needs 5V                           |
| GND     | GND       | Common ground                          |

> Default I2C address: `0x27`. Run an I2C scanner sketch if the display doesn't initialise.

---

## 4×3 Matrix Keypad

| Keypad Row/Col | ESP32 GPIO | Notes                   |
|----------------|-----------|-------------------------|
| Row 1          | GPIO 14   |                         |
| Row 2          | GPIO 27   |                         |
| Row 3          | GPIO 26   |                         |
| Row 4          | GPIO 25   |                         |
| Col 1          | GPIO 15   |                         |
| Col 2          | GPIO 2    |                         |
| Col 3          | GPIO 4    |                         |

> Use the `Keypad.h` library. Pull-up resistors are handled internally by the library.

---

## IR Sensor (Flow Verification)

| IR Sensor Pin | ESP32 GPIO | Notes                              |
|---------------|-----------|-------------------------------------|
| OUT           | GPIO 35   | Digital input, active LOW           |
| VCC           | 3.3V      |                                     |
| GND           | GND       |                                     |

---

## Power Supply Notes

- ESP32 powered via **USB** during development or via **5V regulated supply** on Vin in deployment.
- Load cell (HX711) and LCD share the **5V Vin** rail.
- HX711 data pins operate at **3.3V logic** — compatible with ESP32 directly.
- Servo motor draws up to **500mA** peak — use a **separate 5V/1A supply** in production to avoid brownout resets on the ESP32.

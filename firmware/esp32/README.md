\# ESP32 Firmware – Smart Public Distribution System



This directory contains the embedded firmware for the \*\*Smart PDS vending-machine–based ration dispensing unit\*\* built using ESP32.



The firmware controls authentication, weighing, dispensing logic, and secure cloud logging.



---



\## 🧠 Functional Overview



The ESP32 firmware performs the following operations:



\- Connects to WiFi network

\- Authenticates users (OTP / QR / etc. depending on configuration)

\- Reads weight using Load Cell + HX711

\- Controls dispensing mechanism

\- Displays system messages on 16x2 LCD (I2C)

\- Sends transaction data securely to Firebase

\- Maintains system stability with WiFi reconnection logic



---



\## 🛠 Hardware Requirements



\- ESP32 Development Board  

\- Load Cell + HX711 Amplifier  

\- 16x2 LCD with I2C Module  

\- Servo Motor (for dispensing control)  

\- IR Sensor (optional for flow verification)  

\- Power Supply (5V regulated)



---



\## 📦 Required Libraries



Install the following from Arduino IDE → Library Manager:



\- HX711 by Bogdan Necula

\- LiquidCrystal\_I2C

\- WiFi (built-in for ESP32)

\- HTTPClient (built-in for ESP32)



---



\## ⚙ Configuration



Sensitive credentials are stored in:






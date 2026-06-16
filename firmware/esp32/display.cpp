#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"

// LCD at I2C address 0x27, 16 columns, 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void initDisplay() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
    Serial.println("[Display] LCD initialized.");
}

// General purpose two-line message
void showMessage(String line1, String line2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1.substring(0, 16));  // Clamp to 16 chars per line
    lcd.setCursor(0, 1);
    lcd.print(line2.substring(0, 16));
}

// Shows an error with a prefix marker on line 1
void showError(String errorMsg) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("! ERROR !");
    lcd.setCursor(0, 1);
    lcd.print(errorMsg.substring(0, 16));
    Serial.print("[Display] Error shown: ");
    Serial.println(errorMsg);
}

// Shows a single-line status update (line 2 stays blank)
void showStatus(String statusMsg) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(statusMsg.substring(0, 16));
}

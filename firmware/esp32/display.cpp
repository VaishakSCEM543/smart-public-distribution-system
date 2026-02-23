#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "display.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);

void initDisplay() {
    lcd.init();
    lcd.backlight();
    lcd.clear();
}

void showMessage(String line1, String line2){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);
}

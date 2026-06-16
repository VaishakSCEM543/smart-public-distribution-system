#include "wifi_manager.h"
#include "display.h"
#include "scale.h"
#include "firebase.h"

// How often (ms) to read weight and sync to Firebase
#define SYNC_INTERVAL_MS 10000UL

// Acceptable deviation from target weight before closing servo (grams)
#define DISPENSE_TARGET_G 5000.0f

unsigned long lastSend = 0;

void setup() {
    Serial.begin(115200);

    connectWiFi();
    initDisplay();
    initScale();

    showMessage("Smart PDS", "System Ready");
}

void loop() {
    ensureWiFi();

    if (millis() - lastSend > SYNC_INTERVAL_MS) {

        float weight = readWeight();

        // Build JSON payload for Firebase
        String json = "{";
        json += "\"weight\":\"" + String(weight) + " g\"";
        json += "}";

        // Send to Firebase and reflect result on LCD
        bool sent = sendToFirebase("test_weight", json);

        if (sent) {
            showMessage("Weight:", String(weight) + " g");
        } else {
            showError("Firebase Fail");
        }

        // Example: check if dispensed weight meets target
        if (isWithinTolerance(weight, DISPENSE_TARGET_G)) {
            showMessage("Dispense Done", String(weight) + "g OK");
            retare();  // Re-zero scale for next user
        }

        lastSend = millis();
    }
}

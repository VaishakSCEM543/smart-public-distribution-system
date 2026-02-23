#include "wifi_manager.h"
#include "display.h"
#include "scale.h"
#include "firebase.h"

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

    if (millis() - lastSend > 10000) {

        float weight = readWeight();

        String json = "{";
        json += "\"weight\":\"" + String(weight) + " g\"";
        json += "}";

        sendToFirebase("test_weight", json);

        showMessage("Weight:", String(weight) + " g");

        lastSend = millis();
    }
}

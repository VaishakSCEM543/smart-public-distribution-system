#include "wifi_manager.h"
#include "scale.h"
#include "display.h"
#include "firebase.h"
#include "auth.h"

void setup() {
    connectWiFi();
    initScale();
    initDisplay();
    showMessage("Smart PDS Ready");
}

void loop() {
    ensureWiFi();
    // State machine logic goes here
}

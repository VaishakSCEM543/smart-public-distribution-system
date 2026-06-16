#include <WiFi.h>
#include <HTTPClient.h>
#include "config.h"
#include "firebase.h"

// Sends a JSON payload to Firebase RTDB via HTTP PUT
// Returns true on success (HTTP 200), false otherwise
bool sendToFirebase(String path, String json) {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("[Firebase] ERROR: No WiFi. Skipping upload.");
        return false;
    }

    HTTPClient http;
    String url = "https://" + String(FIREBASE_HOST) + "/" + path + ".json?auth=" + FIREBASE_AUTH;

    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    int code = http.PUT(json);

    if (code == 200) {
        Serial.println("[Firebase] Upload OK (200).");
        http.end();
        return true;
    } else if (code == 401) {
        Serial.println("[Firebase] ERROR 401: Unauthorized. Check FIREBASE_AUTH in config.h.");
    } else if (code == 400) {
        Serial.println("[Firebase] ERROR 400: Bad request. Check JSON payload format.");
    } else if (code < 0) {
        Serial.print("[Firebase] ERROR: HTTP client error code: ");
        Serial.println(code);
    } else {
        Serial.print("[Firebase] Unexpected HTTP response: ");
        Serial.println(code);
    }

    http.end();
    return false;
}

// Stub: reads from Firebase path for OTP/QR verification (not yet implemented)
bool checkNewQR(String &qrData) {
    // TODO: implement GET from /pending_auth/{shopId} in a future version
    return false;
}

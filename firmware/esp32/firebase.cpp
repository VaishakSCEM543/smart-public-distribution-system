#include <WiFi.h>
#include <HTTPClient.h>
#include "config.h"
#include "firebase.h"

void sendToFirebase(String path, String json) {

    HTTPClient http;

    String url = "https://" + String(FIREBASE_HOST) + "/" + path + ".json?auth=" + FIREBASE_AUTH;

    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    int code = http.PUT(json);

    Serial.print("Firebase response: ");
    Serial.println(code);

    http.end();
}

bool checkNewQR(String &qrData){
    return false; // Not used yet
}

#include <WiFi.h>
#include <HTTPClient.h>
#include "config.h"
#include "firebase.h"

void sendToFirebase(String path, String json) {
    HTTPClient http;
    String url = "https://" + String(FIREBASE_HOST) + "/" + path + ".json?auth=" + FIREBASE_AUTH;

    http.begin(url);
    http.addHeader("Content-Type", "application/json");

    for(int i=0; i<3; i++){
        int code = http.PUT(json);
        if(code == 200) break;
        delay(1000);
    }

    http.end();
}

bool checkNewQR(String &qrData){
    HTTPClient http;
    String url = "https://" + String(FIREBASE_HOST) + "/qr.json?auth=" + FIREBASE_AUTH;

    http.begin(url);
    int code = http.GET();

    if(code == 200){
        String payload = http.getString();
        if(payload != "null"){
            qrData = payload;
            http.end();
            return true;
        }
    }

    http.end();
    return false;
}

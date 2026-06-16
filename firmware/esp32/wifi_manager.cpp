#include <WiFi.h>
#include "config.h"
#include "wifi_manager.h"

// Maximum attempts before giving up initial connection
#define WIFI_MAX_RETRIES    20
// Delay between each retry (ms)
#define WIFI_RETRY_DELAY_MS 500

void connectWiFi() {
    Serial.print("[WiFi] Connecting to: ");
    Serial.println(WIFI_SSID);

    WiFi.begin(WIFI_SSID, WIFI_PASS);

    int retries = 0;
    while (WiFi.status() != WL_CONNECTED && retries < WIFI_MAX_RETRIES) {
        delay(WIFI_RETRY_DELAY_MS);
        Serial.print(".");
        retries++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println();
        Serial.print("[WiFi] Connected. IP: ");
        Serial.println(WiFi.localIP());
    } else {
        Serial.println();
        Serial.println("[WiFi] ERROR: Failed to connect. Check SSID/password in config.h.");
    }
}

void ensureWiFi() {
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("[WiFi] Connection lost. Reconnecting...");
        WiFi.disconnect();
        WiFi.begin(WIFI_SSID, WIFI_PASS);

        int retries = 0;
        while (WiFi.status() != WL_CONNECTED && retries < WIFI_MAX_RETRIES) {
            delay(WIFI_RETRY_DELAY_MS);
            retries++;
        }

        if (WiFi.status() == WL_CONNECTED) {
            Serial.println("[WiFi] Reconnected successfully.");
        } else {
            Serial.println("[WiFi] WARNING: Still disconnected. Firebase sync will fail.");
        }
    }
}

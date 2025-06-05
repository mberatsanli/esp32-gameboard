#include "network_manager.h"

NetworkManager* NetworkManager::instance = nullptr;

NetworkManager::NetworkManager() : isConnected(false) {}

NetworkManager* NetworkManager::getInstance() {
    if (instance == nullptr) {
        instance = new NetworkManager();
    }
    return instance;
}

bool NetworkManager::connect() {
    Serial.println("Attempting network connection...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts++ < 10) {
        delay(500);
        Serial.print(".");
    }

    if (WiFi.status() == WL_CONNECTED) {
        isConnected = true;
        ipAddress = WiFi.localIP().toString();
        Serial.println("\n✅ Network connection successful!");
        Serial.print("IP address: ");
        Serial.println(ipAddress);
        return true;
    } else {
        isConnected = false;
        Serial.println("\n�� Network connection failed.");
        return false;
    }
}

void NetworkManager::disconnect() {
    WiFi.disconnect();
    isConnected = false;
    ipAddress = "";
}
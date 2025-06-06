#include "network_manager.h"

NetworkManager* NetworkManager::instance = nullptr;

NetworkManager::NetworkManager() : isConnected(false) {}

NetworkManager* NetworkManager::getInstance() {
    if(instance == nullptr) {
        instance = new NetworkManager();
    }
    return instance;
}

bool NetworkManager::connect() {
    Serial.println("Attempting network connection...");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

    int attempts = 0;
    while(WiFi.status() != WL_CONNECTED && attempts++ < 10) {
        delay(500);
        Serial.print(".");
    }

    if(WiFi.status() == WL_CONNECTED) {
        isConnected = true;
        ipAddress = WiFi.localIP().toString();
        Serial.println("\n✅ Network connection successful!");
        Serial.print("IP address: ");
        Serial.println(ipAddress);
        return true;
    } else {
        isConnected = false;
        Serial.println("\n❌ Network connection failed.");
        return false;
    }
}

bool NetworkManager::connectWebSocket() {
    if(!isConnected) {
        Serial.println("Cannot connect WebSocket: Network not connected");
        return false;
    }

    webSocket.begin("localhost", 3000, "/ws", "ws");
    webSocket.onEvent([this](WStype_t type, uint8_t * payload, size_t length) {
        this->webSocketEvent(type, payload, length);
    });

    Serial.println("WebSocket connection initiated");
    return true;
}

void NetworkManager::webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            isWebSocketConnected = false;
            Serial.println("WebSocket disconnected");
            break;

        case WStype_CONNECTED:
            isWebSocketConnected = true;
            Serial.println("WebSocket connected");
            break;

        case WStype_TEXT:
            Serial.printf("Received text: %s\n", payload);
            break;

        case WStype_BIN:
        case WStype_ERROR:
        case WStype_FRAGMENT_TEXT_START:
        case WStype_FRAGMENT_BIN_START:
        case WStype_FRAGMENT:
        case WStype_FRAGMENT_FIN:
            break;
    }
}

void NetworkManager::sendWebSocketMessage(const char* message) {
    if(isWebSocketConnected) {
        webSocket.sendTXT(message);
    }
}

void NetworkManager::loop() {
    webSocket.loop();
}

void NetworkManager::disconnect() {
    WiFi.disconnect();
    isConnected = false;
    ipAddress = "";
}
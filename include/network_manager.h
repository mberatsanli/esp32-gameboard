#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <WiFi.h>
#include <Arduino.h>
#include <WebSocketsClient.h>

class NetworkManager {
  private:
    static NetworkManager* instance;
    bool isConnected;
    String ipAddress;

    WebSocketsClient webSocket;
    bool isWebSocketConnected;
    void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);

    NetworkManager();

  public:
    static NetworkManager* getInstance();
    bool connect();
    bool isNetworkConnected() const {
        return isConnected;
    }
    String getIpAddress() const {
        return ipAddress;
    }
    void disconnect();

    bool connectWebSocket();
    bool isWebSocketReady() const {
        return isWebSocketConnected;
    }
    void sendWebSocketMessage(const char* message);
    void loop();
};

#endif
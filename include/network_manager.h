#ifndef NETWORK_MANAGER_H
#define NETWORK_MANAGER_H

#include <WiFi.h>
#include <Arduino.h>

class NetworkManager {
private:
    static NetworkManager* instance;
    bool isConnected;
    String ipAddress;
    
    NetworkManager();

public:
    static NetworkManager* getInstance();
    bool connect();
    bool isNetworkConnected() const { return isConnected; }
    String getIpAddress() const { return ipAddress; }
    void disconnect();
};

#endif
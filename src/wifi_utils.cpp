#include "wifi_utils.h"
#include <WiFi.h>
#include <Arduino.h>

void checkWiFiConnection() {
  Serial.println("Attempting WiFi connection...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts++ < 10) {
    delay(500);
    Serial.print(".");
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n✅ WiFi connection successful!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\n🚫 WiFi connection failed.");
  }
}

#include <Arduino.h>
#include "screen.h"
#include "menu.h"
#include "wifi_utils.h"

void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("ESP32 - Game Console initiliazed...");

  showBootScreen();
  checkWiFiConnection();

  changeScreen(SCREEN_MENU);
}

void loop() {
  handleScreenState();
  delay(1000);
}

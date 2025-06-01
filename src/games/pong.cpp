#include <Arduino.h>
#include "games/pong.h"
#include "screen.h"

void runGamePong() {
  Serial.println("🏓 Pong Oyunu Başladı!");
  Serial.println("Çıkmak için herhangi bir tuşa basın...");

  unsigned long start = millis();
  while (millis() - start < 10000) {
    Serial.println("Top gidiyor... 🏓");
    delay(1000);

    if (Serial.available() > 0) {
      Serial.read(); // input temizle
      break;
    }
  }

  Serial.println("Pong oyunu sona erdi.");
  changeScreen(SCREEN_MENU);
}

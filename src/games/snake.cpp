#include <Arduino.h>
#include "games/snake.h"
// #include "screen.h"

void runGameSnake() {
  Serial.println("🐍 Snake Oyunu Başladı!");
  Serial.println("Çıkmak için herhangi bir tuşa basın...");

  unsigned long start = millis();
  while (millis() - start < 10000) {
    Serial.println("Yılan hareket ediyor...");
    delay(1000);

    if (Serial.available() > 0) {
      Serial.read(); // input temizle
      break;
    }
  }

  Serial.println("Snake oyunu sona erdi.");
  // changeScreen(SCREEN_MENU);
}

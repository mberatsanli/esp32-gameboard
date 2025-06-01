#include "menu.h"
#include "screen.h"
#include <Arduino.h>

void showMainMenu() {
  Serial.println("🕹️  Home Screen");
  Serial.println("1 - Snake");
  Serial.println("2 - Pong");
  Serial.println("Please enter a game number of the game:");

  while (Serial.available() == 0) {}

  char choice = Serial.read();
  if (choice == '1') {
    changeScreen(SCREEN_GAME_SNAKE);
  } else if (choice == '2') {
    changeScreen(SCREEN_GAME_PONG);
  } else {
    Serial.println("Undefined choice!");
  }
}

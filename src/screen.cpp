#include "screen.h"
#include "menu.h"
#include "games/snake.h"
#include "games/pong.h"
#include <Arduino.h>

static ScreenState currentScreen = SCREEN_BOOT;

void changeScreen(ScreenState newState) {
  currentScreen = newState;
}

void handleScreenState() {
  switch (currentScreen) {
    case SCREEN_MENU:
      showMainMenu();
      break;
    case SCREEN_GAME_SNAKE:
      runGameSnake();
      break;
    case SCREEN_GAME_PONG:
      runGamePong();
      break;
    default:
      Serial.println("Unknown screen.");
      break;
  }
}

void showBootScreen() {
  Serial.println("Welcome to the ESP32 Game Console!");
  Serial.println("Loading...");
}
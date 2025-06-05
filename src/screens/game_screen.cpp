#include "screens/game_screen.h"
#include "screens/screen_manager.h"

GameScreen::GameScreen(int game) : currentGame(game) {}

void GameScreen::init() {
    Serial.println("Game Screen initialized");
    Serial.print("Selected game: ");
    switch(currentGame) {
        case 0:
            Serial.println("Battleship");
            break;
        case 1:
            Serial.println("Tic-Tac-Toe");
            break;
        case 2:
            Serial.println("Snake");
            break;
    }
}

void GameScreen::loop() {
    // Update game logic
    if (buttons.up.isPressed()) {
        Serial.println("Up pressed in game");
    }
    
    if (buttons.down.isPressed()) {
        Serial.println("Down pressed in game");
    }

    // Draw game screen
    Serial.println("\nGame Screen:");
    switch(currentGame) {
        case 0:
            Serial.println("Playing Battleship...");
            break;
        case 1:
            Serial.println("Playing Tic-Tac-Toe...");
            break;
        case 2:
            Serial.println("Playing Snake...");
            break;
    }
}

#include "screens/game_screen.h"
#include "games/game_registry.h"

GameScreen::GameScreen(int gameIndex) : currentGameIndex(gameIndex) {
    game = GameRegistry::getGameByIndex(gameIndex);
}

void GameScreen::init() {
    Serial.println("Game Screen initialized");

    if (game) {
        Serial.print("Starting game: ");
        Serial.println(game->getName());
        game->init();
    }
}

void GameScreen::loop() {
    if (game) {
        game->loop();
    }
}
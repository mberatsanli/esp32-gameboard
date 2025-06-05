#include "screens/games_screen.h"
#include "screens/screen_manager.h"
#include "display/display.h"
#include "games/game_registry.h"

GamesScreen::GamesScreen() : selectedItem(0) {}

void GamesScreen::init() {
    tft.fillScreen(ILI9341_BLACK);
    drawTitle("Select Game");

    for (int i = 0; i < GameRegistry::getGameCount(); i++) {
        Game* game = GameRegistry::getGameByIndex(i);
        drawMenuItem(game->getName(), i, i == selectedItem);
    }
}

void GamesScreen::loop() {
    static unsigned long lastPress = 0;
    unsigned long now = millis();

    if (buttons.up.isPressed() && buttons.down.isPressed()) {
        screenManager.showMainScreen();
        lastPress = now;
        return;
    }

    if (buttons.action.isPressed() && now - lastPress > 200) {
        Game* game = GameRegistry::getGameByIndex(selectedItem);
        if (game) {
            screenManager.showGameScreen(selectedItem);
        }
        lastPress = now;
    }

    if (buttons.up.isPressed() && now - lastPress > 200) {
        int previous = selectedItem;
        selectedItem = (selectedItem - 1 + GameRegistry::getGameCount()) % GameRegistry::getGameCount();
        updateMenuSelection(previous, selectedItem, nullptr, GameRegistry::getGameCount());
        lastPress = now;
    }

    if (buttons.down.isPressed() && now - lastPress > 200) {
        int previous = selectedItem;
        selectedItem = (selectedItem + 1) % GameRegistry::getGameCount();
        updateMenuSelection(previous, selectedItem, nullptr, GameRegistry::getGameCount());
        lastPress = now;
    }
}
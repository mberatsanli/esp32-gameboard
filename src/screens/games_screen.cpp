#include "screens/games_screen.h"
#include "screens/screen_manager.h"
#include "display/display.h"

GamesScreen::GamesScreen() : selectedItem(0) {}

void GamesScreen::init() {
    Serial.println("Games Screen initialized");
    // Clear the screen
    tft.fillScreen(ILI9341_BLACK);
    
    // Draw title
    drawCenteredText("Select Game", 20, ILI9341_WHITE, 2);
    
    // Draw menu items
    for (int i = 0; i < GAME_COUNT; i++) {
        drawMenuItem(GAMES[i], i, i == selectedItem);
    }
}

void GamesScreen::loop() {
    static unsigned long lastPress = 0;
    unsigned long now = millis();

    if (buttons.up.isPressed() && buttons.down.isPressed()) {
        screenManager.showMainScreen();
        return;
    }

    if (buttons.up.isPressed() && now - lastPress > 200) {
        int previous = selectedItem;
        selectedItem = (selectedItem - 1 + GAME_COUNT) % GAME_COUNT;
        updateMenuSelection(previous, selectedItem, GAMES, GAME_COUNT);
        lastPress = now;
    }

    if (buttons.down.isPressed() && now - lastPress > 200) {
        int previous = selectedItem;
        selectedItem = (selectedItem + 1) % GAME_COUNT;
        updateMenuSelection(previous, selectedItem, GAMES, GAME_COUNT);
        lastPress = now;
    }
}

#include "screens/main_screen.h"
#include "screens/screen_manager.h"
#include "display/display.h"

MainScreen::MainScreen() : selectedItem(0) {}

void MainScreen::init() {
    tft.fillScreen(ILI9341_BLACK);
    drawCenteredText("ESP32 - Game Board", 20, ILI9341_WHITE, 2);
    
    for (int i = 0; i < itemCount; i++) {
        drawMenuItem(menuItems[i], i, i == selectedItem);
    }
}

void MainScreen::loop() {
    static unsigned long lastPress = 0;
    unsigned long now = millis();

    if (buttons.action.isPressed() && now - lastPress > 200) {
        Serial.printf("SELECTED: %d\n", selectedItem);

        lastPress = now;
        switch(selectedItem) {
            case 0:
                screenManager.showGamesScreen();
                break;
            case 1:
                screenManager.showCreditsScreen();
                break;
            case 2:
                screenManager.showCreditsScreen();
                break;
        }
    } else {
        if (buttons.up.isPressed() && now - lastPress > 200) {
            int previous = selectedItem;
            selectedItem = (selectedItem - 1 + itemCount) % itemCount;
            updateMenuSelection(previous, selectedItem, menuItems, itemCount);
            lastPress = now;
        }

        if (buttons.down.isPressed() && now - lastPress > 200) {
            int previous = selectedItem;
            selectedItem = (selectedItem + 1) % itemCount;
            updateMenuSelection(previous, selectedItem, menuItems, itemCount);
            lastPress = now;
        }
    }
}

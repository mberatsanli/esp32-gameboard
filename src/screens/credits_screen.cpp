#include "screens/credits_screen.h"
#include "screens/screen_manager.h"
#include "button_handler.h"

CreditsScreen::CreditsScreen() {}

void CreditsScreen::init() {
    Serial.println("Credits Screen initialized");
}

void CreditsScreen::loop() {
    // Credits screen button controls
    if (buttons.up.isPressed() || buttons.down.isPressed()) {
        // Return to main menu
        screenManager.showMainScreen();
    }

    // Draw credits screen
    Serial.println("\nCredits:");
    Serial.println("ESP32 Game Board");
    Serial.println("Created by: Your Name");
    Serial.println("Contributors:");
    Serial.println("- Contributor 1");
    Serial.println("- Contributor 2");
    Serial.println("\nPress any button to return to main menu");
}

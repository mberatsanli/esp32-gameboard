#include <Arduino.h>
#include "display/display.h"
#include "button_handler.h"
#include "screens/screen_manager.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("ESP32 - Game Board initialized...");

    // Initialize display
    initDisplay();
    
    // Show main menu
    screenManager.init();
}

void loop() {
    // Update screen
    screenManager.loop();
    
    // Small delay
    delay(100);
}
#ifndef CREDITS_SCREEN_H
#define CREDITS_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"

class CreditsScreen : public Screen {
private:
    // Scroll speed in pixels per frame
    static const int SCROLL_SPEED = 1;
    int scrollPosition;
    
    // Credits text array
    const char* credits[17] = {
        "# ESP32 Game Board",
        "",
        "## Development",
        "Melih Berat SANLI (mberatsanli)",
        "",
        "## ---- Games ----",
        "### Battleship",
        "Development: <NOT READY>",
        "### Tic-Tac-Toe",
        "Development: <NOT READY>",
        "### Snake",
        "Development: <NOT READY>",
        "",
        "## Hardware",
        "ESP32",
        "LCD Display (ILI9341)",
        "Buttons",
    };
    const int creditCount = 17;

public:
    CreditsScreen();
    void init() override;
    void loop() override;
};

#endif
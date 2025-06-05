#include "screens/credits_screen.h"
#include "screens/screen_manager.h"
#include "display/display.h"

CreditsScreen::CreditsScreen() : scrollPosition(0) {}

void CreditsScreen::init() {
    // Clear the screen
    tft.fillScreen(ILI9341_BLACK);
    
    // Draw title using drawTitle for consistency
    drawTitle("Credits");
    
    // Initial scroll position
    scrollPosition = 0;
}

void CreditsScreen::loop() {
    if (buttons.up.isPressed() && buttons.down.isPressed()) {
        screenManager.showMainScreen();
        return;
    }
    
    // Update scroll position
    scrollPosition += SCROLL_SPEED;
    
    // Clear screen (except title)
    tft.fillRect(0, 40, tft.width(), tft.height() - 40, ILI9341_BLACK);
    
    // Draw credits
    int y = 60 - scrollPosition;
    for (int i = 0; i < creditCount; i++) {
        if (y > 40 && y < tft.height() - 20) {
            if (strlen(credits[i]) > 0) {
                if (credits[i][0] == '#') {
                    if (credits[i][1] == '#') {
                        if (credits[i][2] == '#') {
                            drawCenteredText(credits[i] + 3, y, ILI9341_BLUE, 1);
                        } else {
                            drawCenteredText(credits[i] + 2, y, ILI9341_GREEN, 1);
                        }
                    } else {
                        drawCenteredText(credits[i] + 1, y, ILI9341_YELLOW, 2);
                    }
                } else {
                    drawCenteredText(credits[i], y, ILI9341_WHITE, 1);
                }
            }
        }
        y += 30;  // Line spacing
    }
    
    // Reset scroll when finished
    if (y < 40) {
        scrollPosition = 0;
    }
    
    // Small delay for smooth animation
    delay(50);
}
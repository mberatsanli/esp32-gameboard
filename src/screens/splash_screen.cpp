#include "screens/splash_screen.h"
#include "screens/screen_manager.h"
#include "display/display.h"

SplashScreen::SplashScreen() : startTime(0), loadingProgress(0) {}

void SplashScreen::init() {
    startTime = millis();
    loadingProgress = 0;
    
    // Clear the screen
    tft.fillScreen(ILI9341_BLACK);
    
    // Draw logo and title
    drawCenteredText("ESP32", tft.height() / 2 - 40, ILI9341_WHITE, 3);
    drawCenteredText("Game Board", tft.height() / 2, ILI9341_WHITE, 2);
    
    // Loading bar frame
    int barWidth = tft.width() - 40;
    int barHeight = 10;
    int barX = 20;
    int barY = tft.height() - 50;
    
    tft.drawRect(barX, barY, barWidth, barHeight, ILI9341_WHITE);
}

void SplashScreen::loop() {
    unsigned long currentTime = millis();
    unsigned long elapsedTime = currentTime - startTime;
    
    // Calculate loading progress and ensure it doesn't exceed 100
    int progress = (elapsedTime * 100) / SPLASH_DURATION;
    loadingProgress = (progress > 100) ? 100 : progress;
    
    // TODO: WiFi connection check
    // TODO: System checks
    
    // Update loading bar
    int barWidth = tft.width() - 40;
    int barHeight = 10;
    int barX = 20;
    int barY = tft.height() - 50;
    
    // Draw progress bar
    int progressWidth = (barWidth * loadingProgress) / 100;
    tft.fillRect(barX, barY, progressWidth, barHeight, ILI9341_GREEN);
    
    // Clear progress text area
    tft.fillRect(0, tft.height() - 40, tft.width(), 20, ILI9341_BLACK);
    
    // Show loading percentage
    char progressText[10];
    sprintf(progressText, "%d%%", loadingProgress);
    drawCenteredText(progressText, tft.height() - 30, ILI9341_WHITE, 1);
    
    // Switch to main menu when time is up
    if (elapsedTime >= SPLASH_DURATION) {
        screenManager.showMainScreen();
    }
}
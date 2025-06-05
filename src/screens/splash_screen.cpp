#include "screens/splash_screen.h"
#include "screens/screen_manager.h"
#include "display/display.h"

SplashScreen::SplashScreen()
    : startTime(0)
    , loadingProgress(0)
    , currentStep(CHECK_SYSTEM) {}

void SplashScreen::init() {
    startTime = millis();
    loadingProgress = 0;
    currentStep = CHECK_SYSTEM;

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

    int const STEP_TIME = 600;

    // Calculate progress for each step
    int stepProgress = (elapsedTime % 600) * 100 / STEP_TIME; // Each step takes 600ms
    loadingProgress = (currentStep * 25) + (stepProgress / 4);

    if(loadingProgress > 100) {
        loadingProgress = 100;
    }

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

    // Show current step message
    drawCenteredText(stepMessages[currentStep], tft.height() - 30, ILI9341_WHITE, 1);

    // Update steps
    if(elapsedTime % STEP_TIME < 50) {
        if(currentStep < DONE) {
            currentStep = (LoadingStep)(currentStep + 1);
        }
    }

    // Network check
    if(currentStep == CHECK_NETWORK) {
        static const int MAX_ATTEMPTS = 3;
        static int currentAttempt = 0;
        static bool networkChecked = false;

        if(!networkChecked) {
            NetworkManager* network = NetworkManager::getInstance();
            if(network->connect()) {
                networkChecked = true;
                currentStep = DONE;
            } else {
                currentAttempt++;
                if(currentAttempt >= MAX_ATTEMPTS) {
                    networkChecked = true;
                    currentStep = DONE;
                }
            }
        }
    }

    if(currentStep == DONE && elapsedTime >= SPLASH_DURATION) {
        screenManager.showMainScreen();
        return;
    }
}
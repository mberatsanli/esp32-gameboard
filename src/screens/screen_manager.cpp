#include "screens/screen_manager.h"

ScreenManager::ScreenManager() 
    : currentScreen(nullptr)
    , mainScreen()
    , gamesScreen()
    , gameScreen(0)
    , creditsScreen() {
}

void ScreenManager::init() {
    showSplashScreen();
}

void ScreenManager::loop() {
    if (currentScreen) {
        currentScreen->loop();
    }
}

void ScreenManager::showSplashScreen() {
    currentScreen = &splashScreen;
    currentScreen->init();
}

void ScreenManager::showMainScreen() {
    currentScreen = &mainScreen;
    currentScreen->init();
}

void ScreenManager::showGamesScreen() {
    currentScreen = &gamesScreen;
    currentScreen->init();
}

void ScreenManager::showGameScreen(int game) {
    gameScreen = GameScreen(game);
    currentScreen = &gameScreen;
    currentScreen->init();
}

void ScreenManager::showCreditsScreen() {
    currentScreen = &creditsScreen;
    currentScreen->init();
}

ScreenManager screenManager;
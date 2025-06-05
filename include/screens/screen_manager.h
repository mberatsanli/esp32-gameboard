#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include "screens/screen.h"
#include "screens/main_screen.h"
#include "screens/games_screen.h"
#include "screens/game_screen.h"
#include "screens/credits_screen.h"
#include "screens/splash_screen.h"
// #include "screens/settings_screen.h"

class ScreenManager {
private:
    Screen* currentScreen;
    MainScreen mainScreen;
    GamesScreen gamesScreen;
    GameScreen gameScreen;
    CreditsScreen creditsScreen;
    SplashScreen splashScreen;
    // SettingsScreen settingsScreen;

public:
    ScreenManager();
    void init();
    void loop();
    
    void showMainScreen();
    void showGamesScreen();
    void showGameScreen(int game);
    void showCreditsScreen();
    void showSplashScreen();
    // void showSettingsScreen();
};

extern ScreenManager screenManager;

#endif
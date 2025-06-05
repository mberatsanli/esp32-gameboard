#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"

class SplashScreen : public Screen {
private:
    unsigned long startTime;
    static const unsigned long SPLASH_DURATION = 3000; // 3 saniye
    int loadingProgress;
    
    // TODO: WiFi connection check
    // TODO: System checks
    // TODO: Other initialization processes

public:
    SplashScreen();
    void init() override;
    void loop() override;
};

#endif
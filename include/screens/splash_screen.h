#ifndef SPLASH_SCREEN_H
#define SPLASH_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"
#include "network_manager.h"

class SplashScreen : public Screen {
  private:
    unsigned long startTime;
    static const unsigned long SPLASH_DURATION = 3000;
    int loadingProgress;

    enum LoadingStep {
        CHECK_SYSTEM,
        CHECK_DISPLAY,
        CHECK_BUTTONS,
        CHECK_NETWORK,
        DONE
    };

    LoadingStep currentStep;
    const char* stepMessages[5] = {
        "Checking System...",
        "Initializing Display...",
        "Testing Buttons...",
        "Checking Network...",
        "Ready!"
    };

  public:
    SplashScreen();
    void init() override;
    void loop() override;
};

#endif
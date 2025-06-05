#ifndef CREDITS_SCREEN_H
#define CREDITS_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"

class CreditsScreen : public Screen {
public:
    CreditsScreen();
    void init() override;
    void loop() override;
};

#endif
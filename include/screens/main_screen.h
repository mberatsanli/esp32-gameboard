#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"

class MainScreen : public Screen {
private:
    int selectedItem;
    const char* menuItems[3] = {"Play", "Credits", "Settings"};
    const int itemCount = 3;

public:
    MainScreen();
    void init() override;
    void loop() override;
};

#endif
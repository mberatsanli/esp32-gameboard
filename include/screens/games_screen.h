#ifndef GAMES_SCREEN_H
#define GAMES_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"
#include "games/games.h"

class GamesScreen : public Screen {
private:
    int selectedItem;

public:
    GamesScreen();
    void init() override;
    void loop() override;
};

#endif
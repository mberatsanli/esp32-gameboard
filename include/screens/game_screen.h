#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"

class GameScreen : public Screen {
private:
    int currentGame;  // 0: Battleship, 1: Tic-Tac-Toe, 2: Snake

public:
    GameScreen(int game);
    void init() override;
    void loop() override;
};

#endif
#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "screens/screen.h"
#include "button_handler.h"
#include "../games/game.h"

class GameScreen : public Screen {
  private:
    int currentGameIndex;  // 0: Battleship, 1: Tic-Tac-Toe, 2: Snake
    Game* game;

  public:
    GameScreen(int gameIndex);
    void init() override;
    void loop() override;
};

#endif
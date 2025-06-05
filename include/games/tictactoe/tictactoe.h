#ifndef GAMES_TICTACTOE_H
#define GAMES_TICTACTOE_H

#include "../game.h"
#include "../game_registry.h"

class TicTacToe : public Game {
  private:
    char board[3][3];
    int currentPlayer; // 0: X, 1: O
    int selectedX;
    int selectedY;

  public:
    TicTacToe() : Game("TicTacToe") {}
    void init() override;
    void loop() override;
};

// Register game
REGISTER_GAME(TicTacToe);

#endif
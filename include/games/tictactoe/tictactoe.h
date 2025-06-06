#ifndef GAMES_TICTACTOE_H
#define GAMES_TICTACTOE_H

#include "../game.h"
#include "../game_registry.h"

enum TicTacToeGameState {
    PLAYING,
    X_WON,
    O_WON,
    DRAW
};

class TicTacToe : public Game {
  private:
    char board[3][3];
    int selectedX;
    int selectedY;

    char currentPlayer;
    static const int CELL_SIZE = 60;
    static const int BOARD_MARGIN = 18;
    static const int LINE_THICKNESS = 2;

    void drawBoard();
    void drawCell(int x, int y, bool selected);
    bool isEmptyCell(int x, int y);
    void markCell(int x, int y);
    void resetBoard();
    void nextPlayer();

    
    TicTacToeGameState gameState;
    TicTacToeGameState decideWinner();

    bool checkLines(int x1, int y1, int x2, int y2, int x3, int y3);
    bool isBoardFull();
    void drawWinnerMessage();
    const char* getWinnerMessage() const;

  public:
    TicTacToe() : Game("TicTacToe")
        , currentPlayer('X')
        , gameState(PLAYING)
        , selectedX(1)
        , selectedY(1) {
          resetBoard();
        }
    void init() override;
    void loop() override;
};

// Register game
REGISTER_GAME(TicTacToe);

#endif
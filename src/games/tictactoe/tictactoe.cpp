#include "games/tictactoe/tictactoe.h"
#include "screens/screen_manager.h";

void TicTacToe::init() {
    tft.fillScreen(ILI9341_BLACK);

    drawTitle("Tic-Tac-Toe");
    resetBoard();
    gameState = PLAYING;
    currentPlayer = 'X';
    drawBoard();
}

void TicTacToe::resetBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void TicTacToe::drawBoard() {
    int boardSize = CELL_SIZE * 3 + LINE_THICKNESS * 2;
    int startX = (tft.width() - boardSize) / 2;
    int startY = (tft.height() - boardSize) / 2;

    // Horizontal
    for(int i = 1; i < 3; i++) {
        int x = startX + i * CELL_SIZE;
        tft.fillRect(x, startY, LINE_THICKNESS, boardSize, ILI9341_WHITE);
    }

    // Vertical
    for(int i = 1; i < 3; i++) {
        int y = startY + i * CELL_SIZE;
        tft.fillRect(startX, y, boardSize, LINE_THICKNESS, ILI9341_WHITE);
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            drawCell(i, j, (i == selectedX && j == selectedY));
        }
    }
}

void TicTacToe::drawCell(int x, int y, bool selected) {
    int startX = (tft.width() - (CELL_SIZE * 3 + LINE_THICKNESS * 2)) / 2;
    int startY = (tft.height() - (CELL_SIZE * 3 + LINE_THICKNESS * 2)) / 2;

    int cellX = startX + x * (CELL_SIZE + LINE_THICKNESS);
    int cellY = startY + y * (CELL_SIZE + LINE_THICKNESS);

    if(selected) {
        tft.drawRect(cellX + 5, cellY + 5, CELL_SIZE - 10, CELL_SIZE - 10, ILI9341_YELLOW);
    } else {
        tft.drawRect(cellX + 5, cellY + 5, CELL_SIZE - 10, CELL_SIZE - 10, ILI9341_BLACK);
    }

    if(board[x][y] != ' ') {
        int centerX = cellX + CELL_SIZE / 2;
        int centerY = cellY + CELL_SIZE / 2;
        int symbolSize = CELL_SIZE / 3;

        if(board[x][y] == 'X') {
            // X
            tft.drawLine(centerX - symbolSize, centerY - symbolSize,
                         centerX + symbolSize, centerY + symbolSize, ILI9341_RED);
            tft.drawLine(centerX + symbolSize, centerY - symbolSize,
                         centerX - symbolSize, centerY + symbolSize, ILI9341_RED);
        } else if(board[x][y] == 'O') {
            // O
            tft.drawCircle(centerX, centerY, symbolSize, ILI9341_BLUE);
        }
    }
}

void TicTacToe::nextPlayer() {
    currentPlayer = currentPlayer == 'X' ? 'O' : 'X';
};

void TicTacToe::markCell(int x, int y) {
    board[x][y] = currentPlayer;
};

bool TicTacToe::isEmptyCell(int x, int y) {
    Serial.printf("isEmptyCell called");
    Serial.printf("Cell[%d][%d] = '%c'\n", x, y, board[x][y]);

    return board[x][y] != 'X' && board[x][y] != 'O';
};

void TicTacToe::loop() {
    static unsigned long lastPress = 0;
    unsigned long now = millis();

    if(gameState == PLAYING) {
        if(buttons.up.isPressed() && now - lastPress > 200) {
            selectedY = (selectedY - 1 + 3) % 3;
            drawBoard();
            lastPress = now;
        }

        if(buttons.down.isPressed() && now - lastPress > 200) {
            selectedY = (selectedY + 1) % 3;
            drawBoard();
            lastPress = now;
        }

        if(buttons.left.isPressed() && now - lastPress > 200) {
            selectedX = (selectedX - 1 + 3) % 3;
            drawBoard();
            lastPress = now;
        }

        if(buttons.right.isPressed() && now - lastPress > 200) {
            selectedX = (selectedX + 1) % 3;
            drawBoard();
            lastPress = now;
        }

        if(buttons.action.isPressed() && now - lastPress > 200) {
            if(isEmptyCell(selectedX, selectedY)) {
                markCell(selectedX, selectedY);
                gameState = decideWinner();

                if(gameState == PLAYING) {
                    nextPlayer();
                } else {
                    drawBoard();
                    drawWinnerMessage();
                }

                drawBoard();
            }
            lastPress = now;
        }
    } else {
        if (buttons.action.isPressed() && now - lastPress > 200) {
            screenManager.showGamesScreen();
            return;
        }
    }

    return;
}

bool TicTacToe::checkLines(int x1, int y1, int x2, int y2, int x3, int y3) {
    char c = board[x1][y1];
    return c != ' ' && c == board[x2][y2] && c == board[x3][y3];
}

bool TicTacToe::isBoardFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

TicTacToeGameState TicTacToe::decideWinner() {
    for(int i = 0; i < 3; i++) {
        if(checkLines(i, 0, i, 1, i, 2)) {
            return board[i][0] == 'X' ? X_WON : O_WON;
        }
    }

    for(int i = 0; i < 3; i++) {
        if(checkLines(0, i, 1, i, 2, i)) {
            return board[0][i] == 'X' ? X_WON : O_WON;
        }
    }

    if(checkLines(0, 0, 1, 1, 2, 2)) {
        return board[0][0] == 'X' ? X_WON : O_WON;
    }
    if(checkLines(0, 2, 1, 1, 2, 0)) {
        return board[0][2] == 'X' ? X_WON : O_WON;
    }

    if(isBoardFull()) {
        return DRAW;
    }

    return PLAYING;
}

const char* TicTacToe::getWinnerMessage() const {
    switch (gameState) {
        case X_WON:
            return "Winner Winner Chicken Dinner - X Wins!";
        case O_WON:
            return "Winner Winner Chicken Dinner - O Wins!";
        case DRAW:
            return "Equely strong... or equely weak?";
        default:
            return "";
    }
}

void TicTacToe::drawWinnerMessage() {
    if (gameState != PLAYING) {
        tft.fillRect(0, tft.height() - 40, tft.width(), 30, ILI9341_BLACK);
        
        const char* message = getWinnerMessage();
        drawCenteredText(message, tft.height() - 60, ILI9341_WHITE, 1);
        drawCenteredText("Press Action to exit", tft.height() - 10, ILI9341_WHITE, 1);
    }
}

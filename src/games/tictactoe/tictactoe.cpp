#include "games/tictactoe/tictactoe.h"

void TicTacToe::init() {
    // resetBoard();

    tft.fillScreen(ILI9341_BLACK);
    drawTitle("Tic-Tac-Toe");
}

void TicTacToe::loop() {
    static unsigned long lastPress = 0;
    unsigned long now = millis();
    
    if (buttons.up.isPressed() && now - lastPress > 200) {
        Serial.printf("Up pressed");
        lastPress = now;
    }


}

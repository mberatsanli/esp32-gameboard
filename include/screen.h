#ifndef SCREEN_H
#define SCREEN_H

enum ScreenState {
  SCREEN_BOOT,
  SCREEN_MENU,
  SCREEN_GAME_SNAKE,
  SCREEN_GAME_PONG
};

void changeScreen(ScreenState newState);
void handleScreenState();
void showBootScreen();

#endif
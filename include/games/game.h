#ifndef GAMES_GAME_H
#define GAMES_GAME_H

#include <Arduino.h>
#include "display/display.h"
#include "button_handler.h"

class Game {
  protected:
    const char* name;

  public:
    Game(const char* gameName): name(gameName) {}

    virtual void init() = 0;
    virtual void loop() = 0;
    virtual ~Game() = default;

    const char* getName() const {
        return name;
    }
};

#endif
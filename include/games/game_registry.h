#ifndef GAMES_GAME_REGISTRY_H
#define GAMES_GAME_REGISTRY_H

#include "game.h"

class GameRegistry {
  private:
    static const int MAX_GAMES = 10;
    static Game* games[MAX_GAMES];
    static int gameCount;

  public:
    static void registerGame(Game* game) {
        if(gameCount < MAX_GAMES) {
            games[gameCount++] = game;
        }
    }

    static Game* getGame(const char* name) {
        for(int i = 0; i < gameCount; i++) {
            if(strcmp(games[i]->getName(), name) == 0) {
                return games[i];
            }
        }
        return nullptr;
    }

    static int getGameCount() {
        return gameCount;
    }
    static Game* getGameByIndex(int index) {
        return games[index];
    }
};

#define REGISTER_GAME(game_class) \
    static game_class game_instance; \
    static struct GameRegistrar_##game_class { \
        GameRegistrar_##game_class() { \
            GameRegistry::registerGame(&game_instance); \
        } \
    } game_registrar_##game_class;

#endif
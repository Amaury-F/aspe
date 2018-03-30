#include "Game.h"

using namespace sf;

/**
 * Fontion principale.
 * Boucle de jeu.
 */
int main() {
    Game game;
    while (game.isRunning()) {
        game.handleEvents();
        game.updateModel();
        game.renderWindow();
    }
    return 0;
}
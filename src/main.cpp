#include "Game.h"

using namespace sf;


int main() {
    Game game;

    while (game.isRunning()) {
        game.handleEvents();
        game.updateModel();
        game.renderWindow();
    }
    return 0;
}
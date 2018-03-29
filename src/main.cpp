#include "Game.h"

using namespace sf;


int main() {
    Game game;

    while (game.isRunning()) {

        while (! sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A));

        game.handleEvents();
        game.updateModel();
        game.renderWindow();


    }
    return 0;
}
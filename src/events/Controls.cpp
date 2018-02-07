//
// Created by amaury on 01/02/18.
//

#include "Controls.h"

using namespace sf;

//trivial, espace <=> jump
std::vector<sf::Keyboard::Key> Controls::bindings {
        Keyboard::Key::Up,
        Keyboard::Key::Down,
        Keyboard::Key::Left,
        Keyboard::Key::Right,
        Keyboard::Key::Space
};

std::vector<sf::Keyboard::Key> Controls::getBindings() {
    return bindings;
}




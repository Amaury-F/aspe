//
// Created by amaury on 01/02/18.
//

#include "Controls.h"

using namespace sf;

//trivial, espace <=> jump
sf::Keyboard::Key Controls::bindings[] {
        Keyboard::Key::Up,
        Keyboard::Key::Down,
        Keyboard::Key::Left,
        Keyboard::Key::Right,
        Keyboard::Key::Space
};

sf::Keyboard::Key * Controls::getBindings() {
    return bindings;
}




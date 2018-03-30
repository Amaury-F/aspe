#include "Controls.h"

using namespace sf;


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




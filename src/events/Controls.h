//
// Created by amaury on 01/02/18.
//

#ifndef JEU2D_CONTROLS_H
#define JEU2D_CONTROLS_H

#include <vector>
#include <SFML/Window/Keyboard.hpp>

//gère les bindings touche-action
class Controls {

public:
    enum Cntrl {
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3,
        JUMP = 4,

        NBR_CTRLS = 5
    };

    static std::vector<sf::Keyboard::Key> getBindings();

private:
    Controls() = default;
    ~Controls() = default;

    //tableau d'association touche-action
    static std::vector<sf::Keyboard::Key> bindings;

};

#endif //JEU2D_CONTROLS_H

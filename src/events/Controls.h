#ifndef JEU2D_CONTROLS_H
#define JEU2D_CONTROLS_H

#include <vector>
#include <SFML/Window/Keyboard.hpp>

/**
 * Gère les inputs (bindings touche-action).
 */
class Controls {

public:
    /**
     * Enumération des différents inputs.
     */
    enum Cntrl {
        UP = 0,
        DOWN = 1,
        LEFT = 2,
        RIGHT = 3,
        JUMP = 4,

        NBR_CTRLS = 5
    };
    /**
     * Getter sur le tableau d'association de touche-action.
     * @return bindings
     */
    static sf::Keyboard::Key * getBindings();

private:
    Controls() = default;
    ~Controls() = default;

    /**
     * Tableau d'association touche-action.
     */
    static sf::Keyboard::Key bindings[NBR_CTRLS];

};

#endif //JEU2D_CONTROLS_H

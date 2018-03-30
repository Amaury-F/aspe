#ifndef JEU2D_EVENTHANDLER_H
#define JEU2D_EVENTHANDLER_H

#include <vector>
#include <SFML/Window/Window.hpp>
#include "Controls.h"

/**
 * Classe principale du paquetage events.
 */
class EventHandler {
public:
    explicit EventHandler(sf::Window *context);
    ~EventHandler();

    /**
     * Réagit aux actions de l'utilisateur (fermeture de la fenêtre déplacement).
     */
    void pullEvents();
    /**
     * Getter sur le tableau des interactions de contrôles.
     * @return keysPressed
     */
    bool * getPressedKeys();

private:
    /**
     * Fenêtre de jeu.
     */
    sf::Window *context;

    /**
     * Tableau des interactions de contrôles (case == enum Cntrl de Controls).
     */
    bool keysPressed[Controls::NBR_CTRLS];

};


#endif //JEU2D_EVENTHANDLER_H

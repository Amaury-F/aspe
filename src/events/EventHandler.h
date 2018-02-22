//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_EVENTHANDLER_H
#define JEU2D_EVENTHANDLER_H

#include <vector>
#include <SFML/Window/Window.hpp>
#include "Controls.h"

//chef du paquetage events
class EventHandler {
public:
    EventHandler(sf::Window *context);
    ~EventHandler();

    void pullEvents();

    //tableau des touches pressées
    bool * getPressedKeys();

private:
    //fenêtre principale
    sf::Window *context;
    //tableau des contrôles préssés (case == enum Cntrl de Controls)
    bool keysPressed[Controls::NBR_CTRLS];

};


#endif //JEU2D_EVENTHANDLER_H

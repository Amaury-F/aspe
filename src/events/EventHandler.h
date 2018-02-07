//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_EVENTHANDLER_H
#define JEU2D_EVENTHANDLER_H

#include <vector>
#include <SFML/Window/Window.hpp>

//chef du paquetage events
class EventHandler {
public:
    EventHandler(sf::Window *context);
    ~EventHandler();

    void pullEvents();
    std::vector<bool> * getPressedKeys() const;

private:
    //fenêtre principale
    sf::Window *context;
    //tableau des contrôles préssés (case == enum Cntrl de Controls)
    std::vector<bool> *keysPressed;

};


#endif //JEU2D_EVENTHANDLER_H

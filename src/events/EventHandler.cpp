//
// Created by amaury on 29/01/18.
//

#include <SFML/Window/Event.hpp>
#include "EventHandler.h"
#include "Controls.h"

using namespace sf;

EventHandler::EventHandler(sf::Window *context):
        context(context)
        {
}

EventHandler::~EventHandler() = default;

bool * EventHandler::getPressedKeys() const {
    return keysPressed;
}

void EventHandler::pullEvents() {


    Event event;
    while (context->pollEvent(event)) {
        if (event.type == Event::Closed) {
            context->close();
        }

    }

    Keyboard::Key *bindings = Controls::getBindings();
    for (int i = 0; i < Controls::NBR_CTRLS; ++i) {
        keysPressed[i] = Keyboard::isKeyPressed(bindings[i]);
    }
}





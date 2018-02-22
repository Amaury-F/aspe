//
// Created by amaury on 29/01/18.
//

#include "GraphicRenderer.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

GraphicRenderer::GraphicRenderer() : context(new RenderWindow(VideoMode(800, 600), "jeu2D")) {
    // Set up graphic rendrering.
    context->setVerticalSyncEnabled(true);
    context->setFramerateLimit(30);
}

GraphicRenderer::~GraphicRenderer() = default; //TODO détruire context

sf::RenderWindow *GraphicRenderer::getContext() {
    return context;
}

void GraphicRenderer::render(Player player) {

    // Init: clearing openGL context.
    context->clear(Color(0, 0, 0));

    // Create player's sprite and colour.
    RectangleShape sprite(Vector2f(16, 16));
    sprite.setFillColor(Color(100, 240, 50));

    // Place sprite.
    Pair pos = player.getPos();
    sprite.move((float) pos.x, (float) pos.y);

    // Draw.
    context->draw(sprite);

    // Display.
    context->display();
}

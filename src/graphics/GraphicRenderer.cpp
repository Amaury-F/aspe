//
// Created by amaury on 29/01/18.
//

#include "GraphicRenderer.h"
#include "SpriteFactory.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>

//TODO charger une seule fois les sprites au lancement du jeu

using namespace sf;

GraphicRenderer::GraphicRenderer() : context(new RenderWindow(VideoMode(800, 600), "jeu2D")) {
    // Set up graphic rendering.
    context->setVerticalSyncEnabled(true);
    context->setFramerateLimit(30);
}

GraphicRenderer::~GraphicRenderer() = default; //TODO détruire context

sf::RenderWindow *GraphicRenderer::getContext() {
    return context;
}

void GraphicRenderer::setTextures() {
    spriteFactory.initTextures();
}

void GraphicRenderer::render(PlayerView player) {

    // Init: clearing openGL context.
    context->clear(Color(0, 0, 0));

    // Set player actual sprite
    spriteFactory.setPlayerSprite(player);

    // Place sprite.
    Sprite sprite = spriteFactory.getSprite();
    Pair pos = player.getPos();
    sprite.move((float) pos.x, (float) pos.y);

    // Draw.
    context->draw(sprite);

    // Display.
    context->display();
}

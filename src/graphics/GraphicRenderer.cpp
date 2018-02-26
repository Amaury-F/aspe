//
// Created by amaury on 29/01/18.
//

#include "GraphicRenderer.h"
#include "../model/ModelConstants.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

GraphicRenderer::GraphicRenderer() : context(new RenderWindow(VideoMode(800, 600), "jeu2D")) {
    // Set up graphic rendrering.
    context->setVerticalSyncEnabled(true);
    context->setFramerateLimit(30);

    //load test level
    setLevelView("../assets/map/test32-32");
}

GraphicRenderer::~GraphicRenderer() = default; //TODO détruire context

sf::RenderWindow *GraphicRenderer::getContext() {
    return context;
}

void GraphicRenderer::render(Player player, const Level &level) {

    // Init: clearing openGL context.
    context->clear(Color(0, 0, 0));

    drawTiles(player.getPos());

    // Create player's sprite and colour.
    RectangleShape sprite(Vector2f(ENTITY_SIZE, ENTITY_SIZE));
    sprite.setFillColor(Color(100, 240, 50));

    // Place sprite.
    Pair pos = player.getPos();
    sprite.move((float) pos.x, (float) pos.y);

    // Draw.
    context->draw(sprite);

    // Display.
    context->display();
}

#define RENDER_DISTANCE 20 * BLOCK_SIZE

void GraphicRenderer::drawTiles(const Pair &playerPos) {

    for (int i = playerPos.x - RENDER_DISTANCE; i <= playerPos.x + RENDER_DISTANCE; i+=BLOCK_SIZE) {
        for (int j = playerPos.y - RENDER_DISTANCE; j <= playerPos.y + RENDER_DISTANCE; j+=BLOCK_SIZE) {

            block b = level->getTileAt(Pair(i, j));

            if (b == Tiles::AIR) {
                RectangleShape airSprite(Vector2f(BLOCK_SIZE, BLOCK_SIZE));
                airSprite.setFillColor(Color(50, 100, 240));

                Pair blockPos = Level::getCellOf(Pair(i, j)) * Pair(BLOCK_SIZE, BLOCK_SIZE);
                airSprite.move((float) blockPos.x, (float) blockPos.y);

                context->draw(airSprite);
            } else {
                RectangleShape groundSprite(Vector2f(BLOCK_SIZE, BLOCK_SIZE));
                groundSprite.setFillColor(Color(240, 50, 100));

                Pair blockPos = Level::getCellOf(Pair(i, j)) * Pair(BLOCK_SIZE, BLOCK_SIZE);
                groundSprite.move((float) blockPos.x, (float) blockPos.y);

                context->draw(groundSprite);
            }
        }
    }
}

void GraphicRenderer::setLevelView(const std::string path) {
    delete level;
    std::string filename = path + "/view.bin";
    level = new LevelView(32, 32);
    level->loadView(filename);
}

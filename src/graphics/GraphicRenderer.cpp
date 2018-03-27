//
// Created by amaury on 29/01/18.
//

#include "GraphicRenderer.h"
#include "../model/ModelConstants.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>

using namespace sf;

GraphicRenderer::GraphicRenderer() : context(new RenderWindow(VideoMode(800, 600), "jeu2D")), view(new View(Vector2f(400, 300), Vector2f(800, 600))) {
    // Set up graphic rendrering.
    context->setVerticalSyncEnabled(true);
    context->setFramerateLimit(30);

    // Set up view
    context->setView(*view);

    //load tileset
    tileset = new TileSet();

    //load test level
    setLevelView("../assets/map/test32-32");
}

GraphicRenderer::~GraphicRenderer() {
    delete context;
    delete tileset;
    delete view;
}

sf::RenderWindow *GraphicRenderer::getContext() {
    return context;
}

sf::View *GraphicRenderer::getView() {
    return view;
}

void GraphicRenderer::render(Player player) {

    // Init: clearing openGL context.
    context->clear(Color(0, 0, 0));

    drawTiles(player.getPos());

    // Create player's sprite and colour.
    RectangleShape sprite(Vector2f(ENTITY_SIZE, ENTITY_SIZE));
    sprite.setFillColor(Color(100, 240, 50));

    // Place sprite.
    Pair pos = player.getPos();
    sprite.move((float) pos.x, (float) pos.y);

    getView()->setCenter(pos.x, pos.y);
    getContext()->setView(*getView());

    // Draw.
    context->draw(sprite);

    // Display.
    context->display();
}

#define RENDER_DISTANCE 40 * BLOCK_SIZE

void GraphicRenderer::drawTiles(const Pair &playerPos) {

    for (int i = playerPos.x - RENDER_DISTANCE; i <= playerPos.x + RENDER_DISTANCE; i+=BLOCK_SIZE) {
        for (int j = playerPos.y - RENDER_DISTANCE; j <= playerPos.y + RENDER_DISTANCE; j+=BLOCK_SIZE) {

            tile t = level->getTileAt(Pair(i, j));

            if (t == TileSet::AIR) {
                RectangleShape airSprite(Vector2f(BLOCK_SIZE, BLOCK_SIZE));
                airSprite.setFillColor(Color(50, 100, 240));

                Pair blockPos = LevelView::getCellOf(Pair(i, j)) * Pair(BLOCK_SIZE, BLOCK_SIZE);
                airSprite.move((float) blockPos.x, (float) blockPos.y);

                context->draw(airSprite);
            } else {
                Sprite sprite;
                Texture texture = *(tileset->getTexture());
                sprite.setTexture(texture);
                sprite.setTextureRect(tileset->tileToRect(t));

                Pair tilePos = LevelView::getCellOf(Pair(i, j)) * Pair(BLOCK_SIZE, BLOCK_SIZE);
                sprite.setPosition((float) tilePos.x, (float) tilePos.y);

                context->draw(sprite);
            }

        }
    }
}

void GraphicRenderer::setLevelView(const std::string path) {
    delete level;
    std::string filename = path + "/view.bin";
    level = new LevelView(32, 32); //TODO : set size based on the path (ex .../foo32-32)
    //TODO : actually, put a setting file in every level dir with size, and possibly other infos (music, shaders...)
    level->loadView(filename);
}

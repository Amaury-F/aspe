#include "GraphicRenderer.h"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

using namespace sf;

GraphicRenderer::GraphicRenderer() :
        context(new RenderWindow(VideoMode(800, 600), "jeu2D", Style::Fullscreen)),
        camera(new View(Vector2f(400, 256), Vector2f(VIEW_WIDTH, VIEW_HEIGHT))) {

    // Met en place le rendu graphique.
    context->setVerticalSyncEnabled(true);
    context->setFramerateLimit(30);

    // Met en place la vue.
    context->setView(*camera);

    // Initialise le tileset.
    tileset = new TileSet();

    // Charge le niveau.
    setLevelView("../assets/map/test128-32");
}

GraphicRenderer::~GraphicRenderer() {
    delete context;
    delete tileset;
    delete camera;
}

sf::RenderWindow *GraphicRenderer::getContext() {
    return context;
}



void GraphicRenderer::render(Player player) {

    // Init: clearing openGL context.
    context->clear(Color(0, 0, 0));

    drawTiles(player.getPos());

    // Crée le sprite et la couleur du joueur.

    // Place le sprite.
    Sprite *sprite = spriteFactory.create(player);
    Pair pos = player.getPos();
    sprite->move((float) pos.x, (float) pos.y);

    camera->setCenter(pos.x, 256);
    getContext()->setView(*camera);

    // Dessine le sprite.
    context->draw(*sprite);

    // Affiche le sprite.
    context->display();
}

#define RENDER_DISTANCE (40 * BLOCK_SIZE)

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
    level = new LevelView(128, 32);
    level->loadView(filename);
}

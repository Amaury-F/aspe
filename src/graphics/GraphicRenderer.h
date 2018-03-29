//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_GRAPHICRENDERER_H
#define JEU2D_GRAPHICRENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../model/player/Player.h"
#include "levelView/LevelView.h"

#define VIEW_WIDTH 800
#define VIEW_HEIGHT 600

//chef du paquetage graphics
class GraphicRenderer {
public:
    GraphicRenderer();
    ~GraphicRenderer();

    sf::RenderWindow * getContext();
    //prendra plus tard un ensemble d'entités à afficher
    void render(Player player);

    /**
     * set view to the levelView stored in path
     */
    void setLevelView(std::string path);

private:
    //contexte d'affichage (fenêtre)
    sf::RenderWindow *context;
    sf::View *camera;

    TileSet *tileset;
    LevelView *level;

    void drawTiles(const Pair &playerPos);
};


#endif //JEU2D_GRAPHICRENDERER_H

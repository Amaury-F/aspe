//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_GRAPHICRENDERER_H
#define JEU2D_GRAPHICRENDERER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../model/player/Player.h"
#include "../model/environment/Blocks.h"
#include "../model/map/Level.h"

//chef du paquetage graphics
class GraphicRenderer {
public:
    GraphicRenderer();
    ~GraphicRenderer();

    sf::RenderWindow * getContext();
    //prendra plus tard un ensemble d'entités à afficher
    void render(Player player, const Level &level);

private:
    //contexte d'affichage (fenêtre)
    sf::RenderWindow *context;

    void drawBlocks(const Pair &playerPos, const Level &level);
};


#endif //JEU2D_GRAPHICRENDERER_H

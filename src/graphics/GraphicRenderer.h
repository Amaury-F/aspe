//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_GRAPHICRENDERER_H
#define JEU2D_GRAPHICRENDERER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "../model/player/Player.h"
#include "SpriteFactory.h"

//chef du paquetage graphics
class GraphicRenderer {
public:
    GraphicRenderer();
    ~GraphicRenderer();

    sf::RenderWindow * getContext();
    //prendra plus tard un ensemble d'entités à afficher
    void render(Player player);

private:
    //contexte d'affichage (fenêtre)
    sf::RenderWindow *context;

    SpriteFactory spriteFactory;
};


#endif //JEU2D_GRAPHICRENDERER_H

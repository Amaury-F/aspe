//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_GRAPHICRENDERER_H
#define JEU2D_GRAPHICRENDERER_H


#include <SFML/Graphics/RenderWindow.hpp>
#include "PlayerView.h"
#include "SpriteFactory.h"

//chef du paquetage graphics
class GraphicRenderer {
public:
    GraphicRenderer();
    ~GraphicRenderer();

    sf::RenderWindow * getContext();
    //prendra plus tard un ensemble d'entités à afficher
    void setTextures();
    void render(PlayerView player);

private:
    //contexte d'affichage (fenêtre)
    sf::RenderWindow *context;
    SpriteFactory spriteFactory;
};


#endif //JEU2D_GRAPHICRENDERER_H

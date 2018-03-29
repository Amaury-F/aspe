#ifndef JEU2D_GRAPHICRENDERER_H
#define JEU2D_GRAPHICRENDERER_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "../model/player/Player.h"
#include "levelView/LevelView.h"
#include "SpriteFactory.h"

#define VIEW_WIDTH 800
#define VIEW_HEIGHT 600

/**
 * Classe principale du paquetage graphics.
 */
class GraphicRenderer {
public:
    GraphicRenderer();
    ~GraphicRenderer();

    /**
     * Getter sur la fenêtre principale.
     * @return context
     */
    sf::RenderWindow * getContext();

    /**
     * Affiche le rendu de(s) entité(s).
     * @param player
     */
    void render(Player player);

    /**
     * Applique la vue stocker au chemin path au levelView.
     */
    void setLevelView(std::string path);

private:
    /**
     * Fenêtre principale.
     */
    sf::RenderWindow *context;

    sf::View *camera;

    /**
     * Fabrique de sprite pour les entités(association sprite-entité).
     */
    SpriteFactory spriteFactory;

    TileSet *tileset;
    LevelView *level;

    /**
     * Applique les sprites aux blocks autour du joueur.
     * @param playerPos
     */
    void drawTiles(const Pair &playerPos);
};


#endif //JEU2D_GRAPHICRENDERER_H

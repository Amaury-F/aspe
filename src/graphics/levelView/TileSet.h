//
// Created by amaury on 26/02/18.
//

#ifndef JEU2D_TILES_H
#define JEU2D_TILES_H


#include <SFML/Graphics/Texture.hpp>

typedef char tile;

class TileSet {
public:
    enum Tles {
        AIR = 0,
        DIRT = 1,
        STONE = 2,

        NBR_TILES = STONE + 1
    };

    TileSet();
    ~TileSet();

    sf::Texture * getTexture();
    sf::IntRect tileToRect(tile t);

private:

    sf::Texture *data;
    unsigned int width;
    unsigned int height;

};


#endif //JEU2D_TILES_H

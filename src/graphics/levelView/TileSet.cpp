//
// Created by amaury on 26/02/18.
//

#include "TileSet.h"
#include "../../model/ModelConstants.h"

using namespace sf;

TileSet::TileSet():
    width(16),
    height(16),
    data(new Texture) {
    data->loadFromFile("../assets/tiles/tileset.png");
}


sf::Texture *TileSet::getTexture() {
    return data;
}

TileSet::~TileSet() {
    delete data;
}

sf::IntRect TileSet::tileToRect(tile t) {
    if (t <= 0) {
        return IntRect(0,0,0,0);
    }
    IntRect r;
    r.left = ((t-1) % width) * BLOCK_SIZE;
    r.top = ((t-1) / width) * BLOCK_SIZE;
    r.width = BLOCK_SIZE;
    r.height = BLOCK_SIZE;
    return r;
}




//
// Created by godarqu1 on 26/02/18.
//

#include <stdexcept>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include "SpriteFactory.h"
#include "../model/ModelConstants.h"


using namespace sf;
using namespace std;

SpriteFactory::SpriteFactory() {}

SpriteFactory::~SpriteFactory() = default;

Sprite * SpriteFactory::create(const Player &entity) {
    Texture *tex;
    string entDesc = entity.describe();
    try {
        tex = textures.at(entDesc);
    } catch (out_of_range &e) {
        tex = new Texture();
        stringstream texturePath;
        texturePath << "../assets/" << entDesc << ".png";
        tex->loadFromFile(texturePath.str());
        textures.insert({entDesc, tex});
    }

    if (entity.describe() == "player") {
        return this->createFromPlayer((Player) entity, tex);
    }
    Sprite * sprite = new Sprite(*tex, IntRect(0, 0, 16, 32));

    return sprite;
}

Sprite * SpriteFactory::createFromPlayer(const Player &player, Texture *texture) {
    int offsetX = 0;
    int offsetY = 0;
    if (player.getOrientation() == -1) {
        offsetY = ENTITY_HEIGHT;
    }

    offsetX = player.getAnimState() / (PLAYER_ANIM_MAX / 4) * ENTITY_WIDTH;
    if (!player.onGround()) {
        offsetX = PLAYER_ANIM_MAX / (PLAYER_ANIM_MAX / 4) * ENTITY_WIDTH;
    }

    return new Sprite(*texture, IntRect(offsetX, offsetY, ENTITY_WIDTH, ENTITY_HEIGHT));
}
#include <stdexcept>
#include <unordered_map>
#include <sstream>
#include "SpriteFactory.h"


using namespace sf;
using namespace std;

SpriteFactory::SpriteFactory() = default;

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

    Pair pSize = player.getSize();

    if (player.getOrientation() == -1) {
        offsetY = pSize.y;
    }

    // Réagit en fonction de l'étape de l'animation du joueur.
    offsetX = player.getAnimState() / (PLAYER_ANIM_MAX / 4) * pSize.x;
    if (!player.onGround()) {
        offsetX = PLAYER_ANIM_MAX / (PLAYER_ANIM_MAX / 4) * pSize.x;
    }

    return new Sprite(*texture, IntRect(offsetX, offsetY, pSize.x, pSize.y));
}
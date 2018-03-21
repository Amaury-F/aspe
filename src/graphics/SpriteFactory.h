//
// Created by godarqu1 on 26/02/18.
//

#ifndef JEU2D_SPRITEFACTORY_H
#define JEU2D_SPRITEFACTORY_H

#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "PlayerView.h"

class SpriteFactory {

public:
    SpriteFactory();
    ~SpriteFactory();

    sf::Sprite getSprite();

    void initTextures();
    void setPlayerSprite(PlayerView player);

private:
    sf::Texture defaultTex;
    sf::Texture playerTex[2][12];
    sf::Sprite sprite;

};

#endif //JEU2D_SPRITEFACTORY_H

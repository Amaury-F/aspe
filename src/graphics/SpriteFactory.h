//
// Created by godarqu1 on 26/02/18.
//

#ifndef JEU2D_SPRITEFACTORY_H
#define JEU2D_SPRITEFACTORY_H

#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "../model/player/Player.h"

class SpriteFactory {

public:
    SpriteFactory();
    ~SpriteFactory();

    sf::Sprite getSprite();
    Player::PlayerState getPreviousState();

    void initTextures();
    void setPlayerSprite(Player player);
    void setPreviousState(Player::PlayerState state);

private:
    sf::Texture defaultTex;
    sf::Texture playerTex[2][4];
    sf::Sprite sprite;
    Player::PlayerState previousState;

};

#endif //JEU2D_SPRITEFACTORY_H

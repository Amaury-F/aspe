//
// Created by godarqu1 on 26/02/18.
//

#include "SpriteFactory.h"
#include <SFML/Graphics/Image.hpp>

#define PLAYER_SPRITE "/home/godarqu1/Documents/Application Informatique/jeu2d/assets/guy.png"

using namespace sf;

SpriteFactory::SpriteFactory() = default;

SpriteFactory::~SpriteFactory() = default;

sf::Sprite SpriteFactory::getSprite() {
    return sprite;
}

void SpriteFactory::initTextures() {
    Image texImg;
    texImg.loadFromFile(PLAYER_SPRITE);

    //Sprite standard (initial et inactif)
    defaultTex.loadFromImage(texImg, sf::IntRect(0, 0, 16, 24));

    for(int k = 0; k < 3; k++) {
        //Sprites du déplacement à droite
        playerTex[0][k].loadFromImage(texImg, sf::IntRect(16, 24, 16, 24));
        playerTex[0][k + 3].loadFromImage(texImg, sf::IntRect(0, 24, 16, 24));
        playerTex[0][k + 6].loadFromImage(texImg, sf::IntRect(48, 24, 16, 24));
        playerTex[0][k + 9].loadFromImage(texImg, sf::IntRect(32, 24, 16, 24));

        //Sprites du déplacement à gauche
        playerTex[1][k].loadFromImage(texImg, sf::IntRect(16, 48, 16, 24));
        playerTex[1][k + 3].loadFromImage(texImg, sf::IntRect(0, 48, 16, 24));
        playerTex[1][k + 6].loadFromImage(texImg, sf::IntRect(48, 48, 16, 24));
        playerTex[1][k + 9].loadFromImage(texImg, sf::IntRect(32, 48, 16, 24));
    }
}

void SpriteFactory::setPlayerSprite(PlayerView player) {
    PlayerView::PlayerState state = player.getState();
    int n = player.getTexValue();
    switch(state) {
        case PlayerView::STANDING:
            sprite.setTexture(defaultTex);
            player.setPreviousState(state);
            break;

        case PlayerView::MOVING_LEFT:
            sprite.setTexture(playerTex[1][n]);
            player.setPreviousState(state);
            break;

        case PlayerView::MOVING_RIGHT:
            sprite.setTexture(playerTex[0][n]);
            player.setPreviousState(state);
            break;
    }
}


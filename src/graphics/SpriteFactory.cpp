//
// Created by godarqu1 on 26/02/18.
//

#include "SpriteFactory.h"

#define PLAYER_SPRITE "/home/godarqu1/Documents/Application Informatique/jeu2d/assets/guy.png"

using namespace sf;

SpriteFactory::SpriteFactory() {}

SpriteFactory::~SpriteFactory() = default;

sf::Sprite SpriteFactory::getSprite() {
    return sprite;
}

Player::PlayerState SpriteFactory::getPreviousState() {
    return previousState;
}

void SpriteFactory::setPreviousState(Player::PlayerState state) {
    previousState = state;
}

void SpriteFactory::initTextures() {
    //Sprite standard (initial et inactif)
    defaultTex.loadFromFile(PLAYER_SPRITE, sf::IntRect(0, 0, 16, 24));

    //Sprites du déplacement à droite
    playerTex[0][0].loadFromFile(PLAYER_SPRITE, sf::IntRect(16, 24, 16, 24));
    playerTex[0][1].loadFromFile(PLAYER_SPRITE, sf::IntRect(0, 24, 16, 24));
    playerTex[0][2].loadFromFile(PLAYER_SPRITE, sf::IntRect(48, 24, 16, 24));
    playerTex[0][3].loadFromFile(PLAYER_SPRITE, sf::IntRect(32, 24, 16, 24));

    //Sprites du déplacement à gauche
    playerTex[1][0].loadFromFile(PLAYER_SPRITE, sf::IntRect(16, 48, 16, 24));
    playerTex[1][1].loadFromFile(PLAYER_SPRITE, sf::IntRect(0, 48, 16, 24));
    playerTex[1][2].loadFromFile(PLAYER_SPRITE, sf::IntRect(48, 48, 16, 24));
    playerTex[1][3].loadFromFile(PLAYER_SPRITE, sf::IntRect(32, 48, 16, 24));
}

void SpriteFactory::setPlayerSprite(Player player) {
    Player::PlayerState state = player.getState();
    int n = player.getTexValue();
    switch(state) {
        case Player::STANDING:
            sprite.setTexture(defaultTex);
            setPreviousState(state);
            break;

        case Player::MOVING_LEFT:
            sprite.setTexture(playerTex[1][n]);
            setPreviousState(state);
            break;

        case Player::MOVING_RIGHT:
            sprite.setTexture(playerTex[0][n]);
            setPreviousState(state);
            break;
    }
}


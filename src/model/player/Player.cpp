//
// Created by amaury on 29/01/18.
//

#include "Player.h"
#include "../../events/EventHandler.h"

#define GROUND_Y 300

using namespace sf;

Player::Player(Pair pos): pos(pos), speed(0,0) {}


void Player::moveTo(Pair pos) {
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}

void Player::setSpeed(Pair speed) {
    this->speed.x = speed.x;
    this->speed.y = speed.y;
}

void Player::move(Pair speed) {
    moveTo(pos + speed);
}

bool Player::onGround() {
    //TODO check Ground under player.
    return pos.y >= GROUND_Y;
}

//
// Created by amaury on 29/01/18.
//

#include "Player.h"


#define GRAVITY 6
#define GROUND_Y 252


Player::Player(Pair pos): pos(pos), speed(0,0) {}


void Player::moveTo(Pair pos) {
    this->pos.x = pos.x;
    this->pos.y = pos.y;
}

void Player::setSpeed(Pair speed) {
    this->speed.x = speed.x;
    this->speed.y = speed.y;
}

void Player::move() {
    moveTo(pos + speed);
}

bool Player::onGround() const {
    //TODO check Ground under player.
    return pos.y >= GROUND_Y;
}


void Player::update() {

    speed += Pair(0,GRAVITY);

    if (onGround() && speed.y > 0) {
        speed.y = 0;
    }

    move();
}

std::string Player::describe() const {
    return "player";
}

void Player::setAnimState(int anim) {
    this->anim = anim;
}

void Player::setOrientation(int o) {
    if (o == 0) {
        lastXDir = 0;
    } else if (o > 0) {
        lastXDir = 1;
    } else {
        lastXDir = -1;
    }
}


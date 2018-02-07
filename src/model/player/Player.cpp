//
// Created by amaury on 29/01/18.
//

#include "Player.h"
#include "../../events/EventHandler.h"
#include "../../events/Controls.h"

#define GRAVITY 6
#define GROUND_Y 300

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

bool Player::onGround() {
    //TODO check Ground under player.
    return pos.y >= GROUND_Y;
}

void Player::handleKeys(std::vector<bool> *keysPressed) {
    Pair speed(0,0);

    // Set speed according to keys
    if ((*keysPressed)[Controls::LEFT]) {
        speed += Pair(-5, 0);
    }
    if ((*keysPressed)[Controls::RIGHT]) {
        speed += Pair(5, 0);
    }

    if ((*keysPressed)[Controls::JUMP] && onGround()) {
        speed += Pair(0, -10);
    }

    setSpeed(speed);
}


void Player::update(std::vector<bool> *keysPressed) {
    setSpeed(Pair(0,0));
    handleKeys(keysPressed);

    speed += Pair(0,GRAVITY);

    if (onGround() && speed.y > 0) {
        speed.y = 0;
    }

    move();
}




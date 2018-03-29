//
// Created by amaury on 29/01/18.
//

#include <cmath>
#include "Player.h"
#include "../ModelConstants.h"


#define GRAVITY 6
#define GROUND_Y 252


Player::Player(Pair pos, CollisionHandler *collisionHandler):
        pos(pos),
        speed(0,0),
        size(STD_SIZE, STD_SIZE + (STD_SIZE / 2)),
        collisionHandler(collisionHandler)
{}


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

bool Player::canMoveTo(Pair pos) {
    std::vector<block> colliders = collisionHandler->getColliders(pos, size.x, size.y);

    bool res = true;
    for (block b : colliders) {
        if (! Blocks::isAir(b)) {
            res = false;
        }
    }

    return res;
}

void Player::update() {
    int xShift = 0;
    int yShift = 0;

    speed += Pair(0,GRAVITY);


    if (onGround() && getSpeed().y > 0) {
        speed.y = 0;
    }

    if (canMoveTo(getPos() + getSpeed())) {
        move();
    } else {

        int i;
        int xDir = 0 + (std::signbit(speed.x) ? -1 : 1);
        int yDir = 0 + (std::signbit(speed.y) ? -1 : 1);
        for (i = 0; i < abs(getSpeed().x); i++) {
            if (canMoveTo(pos + Pair(xDir, 0))) {
                xShift += xDir;
            }
        }

        for (i = 0; i < abs(getSpeed().y); i++) {
            if (canMoveTo(pos + Pair(0, yDir))) {
                xShift += yDir;
            }
        }

        moveTo(pos + Pair(xShift,yShift));
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


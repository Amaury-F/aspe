//
// Created by amaury on 29/01/18.
//

#include <cmath>
#include "Player.h"
#include "../ModelConstants.h"


#define GRAVITY 1
#define FRICTION 1
#define CLIMB_SIZE 5


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
    return ! canMoveTo(Pair(pos.x, pos.y+1));
}

bool Player::canMoveTo(Pair pos) const {
    std::vector<block> colliders = collisionHandler->getColliders(pos, size);
    return colliders.empty();
}

void Player::update() {
    int xShift = 0;
    int yShift = 0;

    //acceleration
    speed += Pair(0,GRAVITY);
    if (speed.x > 0) {
        speed.x -= FRICTION;
    } else if (speed.x < 0) {
        speed.x += FRICTION;
    }


    //speed cap
    if (abs(speed.y) > 10) {
        speed.y = sign(speed.y) * 10;
    }
    if (abs(speed.x) > 5) {
        speed.x = sign(speed.x) * 5;
    }


    if (onGround() && speed.y > 0) {
        speed.y = 0;
    }


    if (canMoveTo(getPos() + getSpeed())) {
        move();
        return;
    }


    int xs = 0;
    int ys = 0;

    int xDir = sign(speed.x);
    int yDir = sign(speed.y);

    while (ys <= abs(speed.y) && canMoveTo(pos + Pair(0, ys * yDir))) {
        ++ys;
    }
    yShift = (ys - 1) * yDir;

    while (xs <= abs(speed.x)) {

        int k = 0;
        for (k = 0; k <= CLIMB_SIZE; ++k) {
            if (canMoveTo(pos + Pair(xs * xDir, -k))) {
                ++xs;
                ys -= k;
                break;
            }
        }
        if (k == CLIMB_SIZE + 1) {
            break;
        }


    }
    xShift = (xs - 1) * xDir;




    speed = Pair(xShift, yShift);
    move();
}

std::string Player::describe() const {
    return "player";
}

void Player::setAnimState(int anim) {
    this->anim = anim;
}

void Player::setOrientation(int o) {
    lastXDir = sign(o);
}

int Player::sign(int n) {
    return 0 + (std::signbit(n) ? -1 : 1);
}
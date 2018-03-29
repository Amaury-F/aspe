//
// Created by godarqu1 on 12/03/18.
//

#include "PlayerView.h"

#define GRAVITY 6

PlayerView::PlayerView(Pair pos) : Player(pos) {}

void PlayerView::setPreviousState(PlayerState state) {
    this->previousState = state;
}

void PlayerView::handleKeys(const bool *keysPressed) {
    Pair speed(0,0);

    this->state = STANDING;

    // Set speed according to keys
    if (keysPressed[Controls::LEFT]) {
        speed += Pair(-5, 0);
        this->state = MOVING_LEFT;
        if (getPreviousState() != getState()) {
            this->texValue = 0;
        } else {
            this->texValue = (this->texValue + 1) % 12;
        }
        setPreviousState(this->state);
    }

    if (keysPressed[Controls::RIGHT]) {
        speed += Pair(5, 0);
        this->state = MOVING_RIGHT;
        this->texValue = (this->texValue + 1) % 12;
    }

    if (keysPressed[Controls::JUMP] && onGround()) {
        speed += Pair(0, -50);
    }

    setSpeed(speed);
}

void PlayerView::update(const bool *keysPressed) {
    setSpeed(Pair(0,0));
    handleKeys(keysPressed);

    Pair spd = getSpeed();
    spd += Pair(0,GRAVITY);

    if (onGround() && spd.y > 0) {
        spd.y = 0;
    }

    move(spd);
}
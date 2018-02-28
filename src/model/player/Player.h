//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_PLAYER_H
#define JEU2D_PLAYER_H

#include <vector>
#include "../Pair.h"

// C'est le joueur.
class Player {

public:
    enum PlayerState {
        STANDING = 0,
        MOVING_RIGHT = 1,
        MOVING_LEFT = 2
    };

    Player(Pair pos);

    Pair getPos() const {return pos;};
    Pair getSpeed() const {return speed;};
    bool onGround();
    PlayerState getState() {return state;};
    int getTexValue() {return texValue;};

    //tout le mouvement, etc
    void update(const bool *keysPressed);

    void moveTo(Pair pos);
    void handleKeys(const bool *keysPressed);
    void setSpeed(Pair speed);
    void move();

private:
    Pair pos;
    Pair speed;
    PlayerState state = STANDING;
    PlayerState previousState = STANDING;
    int texValue = 0;

};


#endif //JEU2D_PLAYER_H

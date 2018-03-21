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
    Player(Pair pos);

    Pair getPos() const {return pos;};
    Pair getSpeed() const {return speed;};
    bool onGround();

    //tout le mouvement, etc
    void moveTo(Pair pos);
    void setSpeed(Pair speed);
    void move(Pair speed);

private:
    Pair pos;
    Pair speed;
};


#endif //JEU2D_PLAYER_H

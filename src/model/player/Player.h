#ifndef JEU2D_PLAYER_H
#define JEU2D_PLAYER_H

#include <vector>
#include <string>
#include "../Pair.h"
#include "../CollisionHandler.h"

#define PLAYER_ANIM_MAX 16

// C'est le joueur.
class Player {

public:

    Player(Pair pos, CollisionHandler *collisionHandler);

    Pair getPos() const {return pos;};
    Pair getSpeed() const {return speed;};
    bool onGround() const;
    std::string describe() const;
    int getAnimState() const {return anim;};
    int getOrientation() const {return lastXDir;};
    Pair getSize() const { return size;};

    //tout le mouvement, etc
    void update();

    void moveTo(Pair pos);
    void setSpeed(Pair speed);
    void setAnimState(int anim);
    void setOrientation(int o);
    void move();

private:
    Pair pos;
    Pair speed;
    Pair size;
    int anim = 0;
    int lastXDir = 1;

    bool canMoveTo(Pair pos) const;
    int sign(int n);

    CollisionHandler *collisionHandler;

};


#endif //JEU2D_PLAYER_H

//
// Created by amaury on 29/03/18.
//

#ifndef JEU2D_COLLISIONHANDLER_H
#define JEU2D_COLLISIONHANDLER_H

#include <vector>
#include "map/Level.h"
#include "ModelConstants.h"


class CollisionHandler {
public :

    CollisionHandler();
    ~CollisionHandler();
    void setLevel(Level *level);
    std::vector<block> getColliders(Pair pos, Pair size);


private :
    Level * level;
};


#endif //JEU2D_COLLISIONHANDLER_H

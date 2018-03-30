#ifndef JEU2D_COLLISIONHANDLER_H
#define JEU2D_COLLISIONHANDLER_H

#include <vector>
#include "map/Level.h"
#include "ModelConstants.h"


class CollisionHandler {
public :

    CollisionHandler();
    ~CollisionHandler();

    /**
     * Donne le level au collisionHandler.
     * @param level
     */
    void setLevel(Level *level);

    /**
     * Renvoie les blocks avec lesquelles le joueur vas entrer en collision.
     * @param pos
     * @param size
     * @return
     */
    std::vector<block> getColliders(Pair pos, Pair size);


private :
    Level * level;
};


#endif //JEU2D_COLLISIONHANDLER_H

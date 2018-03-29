//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_GAMEMODEL_H
#define JEU2D_GAMEMODEL_H


#include "player/Player.h"
#include "map/Level.h"
#include "CollisionHandler.h"

class GameModel {
public :
    GameModel();
    ~GameModel();

    void update(const bool *keysPressed);
    Player getPlayer();
    Player getEntities();
    Level * getLevel();
    void loadLevel(Level *level);

    void handleKeys(const bool *keysPressed);



private :
    Player *player;
    Level *level;

    CollisionHandler *collisionHandler;
};


#endif //JEU2D_GAMEMODEL_H

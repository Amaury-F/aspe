//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_GAMEMODEL_H
#define JEU2D_GAMEMODEL_H


#include "player/Player.h"

class GameModel {
public :
    GameModel();
    ~GameModel();

    void update(std::vector<bool> *keysPressed);
    Player getEntities();

private :
    Player *player;
};


#endif //JEU2D_GAMEMODEL_H

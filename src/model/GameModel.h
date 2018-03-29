//
// Created by amaury on 29/01/18.
//

#ifndef JEU2D_GAMEMODEL_H
#define JEU2D_GAMEMODEL_H


#include "../graphics/PlayerView.h"
#include "../graphics/SpriteFactory.h"

class GameModel {
public :
    GameModel();
    ~GameModel();

    void update(const bool *keysPressed);
    PlayerView getEntities();

private :
    PlayerView *player;
};


#endif //JEU2D_GAMEMODEL_H

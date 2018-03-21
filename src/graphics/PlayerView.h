//
// Created by godarqu1 on 12/03/18.
//

#ifndef JEU2D_PLAYERVIEW_H
#define JEU2D_PLAYERVIEW_H

#include "../model/player/Player.h"
#include "../model/Pair.h"
#include "../events/Controls.h"

// C'est la vue du joueur.
class PlayerView : public Player {

public:
    enum PlayerState {
        STANDING = 0,
        MOVING_RIGHT = 1,
        MOVING_LEFT = 2
    };

    PlayerView(Pair pos);

    PlayerState getState() {return state;};
    PlayerState getPreviousState() {return previousState;};
    int getTexValue() {return texValue;};

    void setPreviousState(PlayerState state);
    void handleKeys(const bool *keysPressed);
    void update(const bool *keysPressed);

private:
    PlayerState state = STANDING;
    PlayerState previousState = STANDING;
    int texValue = 0;

};

#endif //JEU2D_PLAYERVIEW_H

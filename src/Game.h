//
// Created by fauveama on 18/01/18.
//

#ifndef JEU2D_GAME_H
#define JEU2D_GAME_H

#include "events/EventHandler.h"
#include "graphics/GraphicRenderer.h"
#include "model/GameModel.h"

class Game {

public:
    Game();
    ~Game();

    void handleEvents();
    void updateModel();
    void renderWindow();
    bool isRunning();

private:
    EventHandler *eventHandler;
    GraphicRenderer *graphicRenderer;
    GameModel *gameModel;


};


#endif //JEU2D_GAME_H

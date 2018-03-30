#ifndef JEU2D_GAME_H
#define JEU2D_GAME_H

#include "events/EventHandler.h"
#include "graphics/GraphicRenderer.h"
#include "model/GameModel.h"

/**
 * Classe principale.
 * Fait la liaison entre chaque partie de l'architecture MVC.
 */
class Game {

public:
    Game();
    ~Game();

    /**
     * Gère les évènements.
     */
    void handleEvents();
    /**
     * Met à jour le modèle.
     */
    void updateModel();
    /**
     * Met à jour la vue.
     */
    void renderWindow();
    /**
     * Indique si le jeu est en cours de fonctionnement.
     */
    bool isRunning();

private:
    EventHandler *eventHandler;
    GraphicRenderer *graphicRenderer;
    GameModel *gameModel;


};


#endif //JEU2D_GAME_H

#ifndef JEU2D_GAMEMODEL_H
#define JEU2D_GAMEMODEL_H


#include "player/Player.h"
#include "map/Level.h"
#include "CollisionHandler.h"

/**
 * Classe principale du paquetage modèle.
 * Fait la liaison entre tout les acteurs du modèles.
 */
class GameModel {
public :
    GameModel();
    ~GameModel();

    /**
     * Met à jour les entités.
     * @param keysPressed
     */
    void update(const bool *keysPressed);

    /**
     * Renvoie le(s) entité(s).
     * @return player
     */
    Player getEntities();

    /**
     * Réagit en fonction des inputs.
     * @param keysPressed
     */
    void handleKeys(const bool *keysPressed);



private :
    Player *player;
    Level *level;

    CollisionHandler *collisionHandler;
};


#endif //JEU2D_GAMEMODEL_H

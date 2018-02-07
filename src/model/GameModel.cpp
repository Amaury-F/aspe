//
// Created by amaury on 29/01/18.
//

#include <vector>
#include "GameModel.h"
#include "../events/EventHandler.h"

//TODO trouver meilleure initialisation
GameModel::GameModel(): player(new Player(Pair(0,0))) {
}

void GameModel::update(std::vector<bool> *keysPressed) {
    player->update(keysPressed);
}

Player GameModel::getEntities() {
    return *player;
}

GameModel::~GameModel() = default;

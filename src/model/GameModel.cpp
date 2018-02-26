//
// Created by amaury on 29/01/18.
//

#include <vector>
#include <iostream>
#include "GameModel.h"
#include "../events/EventHandler.h"


GameModel::GameModel(): player(new Player(Pair(0,0))) {
    level = new Level(32, 32);
    level->loadTerrain("../assets/map/test32-32/level.bin");
}

void GameModel::update(const bool *keysPressed) {
    player->update(keysPressed);
}

Player GameModel::getEntities() {
    return *player;
}

Level * GameModel::getLevel() {
    return level;
}

void GameModel::loadLevel(Level *level) {
    this->level = level;
}

GameModel::~GameModel() = default;

//
// Created by amaury on 29/01/18.
//

#include <vector>
#include <iostream>
#include "GameModel.h"
#include "../events/Controls.h"


GameModel::GameModel(): collisionHandler(new CollisionHandler()) {
    level = new Level(128, 32);
    level->loadTerrain("../assets/map/test128-32/level.bin");

    collisionHandler->setLevel(level);
    player = new Player(Pair(0,0), collisionHandler);
}

void GameModel::update(const bool *keysPressed) {
    handleKeys(keysPressed);
    player->update();
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

Player GameModel::getPlayer() {
    return *player;
}

void GameModel::handleKeys(const bool *keysPressed) {
    Pair speed(0,0);

    // Set speed according to keys
    if (keysPressed[Controls::LEFT]) {
        speed += Pair(-5, 0);
        player->setOrientation(-1);
        player->setAnimState(player->getAnimState() + 1);
    }

    if (keysPressed[Controls::RIGHT]) {
        speed += Pair(5, 0);
        player->setOrientation(1);
        player->setAnimState(player->getAnimState() + 1);
    }

    if (speed.x == 0 || player->getAnimState() >= PLAYER_ANIM_MAX) {
        player->setAnimState(0);
    }

    if (keysPressed[Controls::JUMP] && player->onGround()) {
        speed += Pair(0, -15);
    }

    player->setSpeed(player->getSpeed() + speed);
}




GameModel::~GameModel() = default;

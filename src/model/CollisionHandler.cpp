//
// Created by amaury on 29/03/18.
//

#include "CollisionHandler.h"


CollisionHandler::CollisionHandler() {
    level = nullptr;
};

std::vector<block> CollisionHandler::getColliders(Pair pos, Pair size) {

    std::vector<block> colliders;

    int i1 = pos.x;
    int j1 = pos.y;
    int i2 = pos.x + size.x - 1;
    int j2 = pos.y + size.y - 1;

    int i,j;
    for (i = i1; i < i2; i += 1) {
        for(j = j1; j < j2; j += 1) {

            block b = level->getBlockAt(Pair(i, j));
            colliders.push_back(b);
        }
    }


    return colliders;
}

void CollisionHandler::setLevel(Level *level) {
    this->level = level;
}

CollisionHandler::~CollisionHandler() = default;

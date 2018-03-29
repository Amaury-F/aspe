//
// Created by amaury on 29/03/18.
//

#include "CollisionHandler.h"


CollisionHandler::CollisionHandler() {
    level = nullptr;
};

std::vector<block> CollisionHandler::getColliders(Pair pos, int width, int height) {

    std::vector<block> colliders;

    int i1 = pos.x;
    int j1 = pos.y;
    int i2 = (pos.x + width);
    int j2 = (pos.y + height);

    int i,j;
    std::cout << "_______" << std::endl;
    for(i = i1; i < i2 + BLOCK_SIZE; i += BLOCK_SIZE) {
        for(j = j1; j < j2 + BLOCK_SIZE; j += BLOCK_SIZE) {

            block b = level->getBlockAt(Pair(i, j));
            std::cout << (int) b << std::endl;
            colliders.push_back(b);
        }
    }

    return colliders;
}

void CollisionHandler::setLevel(Level *level) {
    this->level = level;
}

CollisionHandler::~CollisionHandler() = default;

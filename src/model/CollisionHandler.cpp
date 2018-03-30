#include "CollisionHandler.h"


CollisionHandler::CollisionHandler() {
    level = nullptr;
};

std::vector<block> CollisionHandler::getColliders(Pair pos, Pair size) {

    // Tableau contenant l'enssemble des blocks solides qui rentreront en collision avec l'entité.
    std::vector<block> colliders;

    // Abscisse du point en haut à gauche de la prochaine checkbox du joueur.
    int i1 = pos.x;
    // Ordonnée du point en haut à gauche de la prochaine checkbox du joueur.
    int j1 = pos.y;
    // Abscisse du point en bas à droite de la prochaine checkbox du joueur.
    int i2 = pos.x + size.x - 1;
    // Ordonnée du point en bas à droite de la prochaine checkbox du joueur.
    int j2 = pos.y + size.y - 1;

    /*
     * On parcours tout les points (en haut, à gauche, en bas, à droite du personnage)
     * de la prochaine positions (pos) de l'entités afin de savoir si ils sont ou non
     * en contact avec un bloc solide.
     */
    int i,j;
    for (i = i1; i < i2; i += 1) {
        for(j = j1; j < j2; j += 1) {
            block b = level->getBlockAt(Pair(i, j));
            if(Blocks::isSlope(b)) {

                int irel = i % BLOCK_SIZE;
                int jrel = j % BLOCK_SIZE;

                if(Blocks::isDown(b)) {
                    if (jrel > Blocks::slope(irel, b)) {
                        colliders.push_back(b);
                    }
                }
                if(Blocks::isUp(b)) {
                    if (jrel < Blocks::slope(irel, b)) {
                        colliders.push_back(b);
                    }
                }
            } else if (!Blocks::isAir(b)){
                colliders.push_back(b);
            }
        }
    }


    return colliders;
}

void CollisionHandler::setLevel(Level *level) {
    this->level = level;
}

CollisionHandler::~CollisionHandler() = default;

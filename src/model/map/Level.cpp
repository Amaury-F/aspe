//
// Created by amaury on 23/02/18.
//

#include <fstream>
#include <iostream>
#include "Level.h"
#include "../ModelConstants.h"

using namespace std;

Level::Level(size_t w, size_t h):
    width(w),
    height(h),
    terrain(new block*[width]) {

    for (size_t i = 0; i < width; ++i) {
        terrain[i] = new block[height];
    }
}

Level::~Level() {

}

void Level::loadTerrain(std::string filename) {
    ifstream in(filename, ios::in);
    if (!in) {
        throw invalid_argument("cannot open file.");
    }

    for (size_t j = 0; j < height; ++j) {
        for (size_t i = 0; i < width; ++i) {
            in.get(terrain[i][j]);
        }
    }
    in.close();
}

block Level::getBlockAt(Pair pos) {
    if (pos.x < 0 || pos.y < 0 || pos.x >= width || pos.y >= height) {
        return Blocks::AIR;
    }

    Pair cell(pos);
    cell.x /= BLOCK_SIZE;
    cell.y /= BLOCK_SIZE;

    return terrain[cell.x][cell.y];
}



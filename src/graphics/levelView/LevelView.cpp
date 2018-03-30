//
// Created by amaury on 26/02/18.
//

#include <fstream>
#include "LevelView.h"
#include "../../model/ModelConstants.h"


using namespace std;

LevelView::LevelView(size_t w, size_t h):
        width(w),
        height(h),
        terrain(new tile*[w]) {

    for (size_t i = 0; i < width; ++i) {
        terrain[i] = new tile[height];
    }
}

LevelView::~LevelView() = default;

void LevelView::loadView(std::string filename) {
    ifstream in(filename, ios::in);
    if (!in) {
        throw invalid_argument("cannot open file : " + filename);
    }

    for (size_t j = 0; j < height; ++j) {
        for (size_t i = 0; i < width; ++i) {
            in.get(terrain[i][j]);
        }
    }
    in.close();
}

tile LevelView::getTileAt(Pair pos) const {
    if (pos.x < 0 || pos.y < 0 || pos.x >= width * BLOCK_SIZE || pos.y >= height * BLOCK_SIZE) {
        return 0;
    }

    Pair cell = getCellOf(pos);

    return terrain[cell.x][cell.y];
}

Pair LevelView::getCellOf(Pair pos) {
    return pos / Pair(BLOCK_SIZE, BLOCK_SIZE);
}

Pair LevelView::getSize() const {
    return Pair((int) width, (int) height);
}


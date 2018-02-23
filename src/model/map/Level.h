//
// Created by amaury on 23/02/18.
//

#ifndef JEU2D_LEVEL_H
#define JEU2D_LEVEL_H


#include <cstdlib>
#include <string>
#include "../environment/Blocks.h"
#include "../Pair.h"

class Level {
public:
    Level(size_t w, size_t h);
    ~Level();

    /**
     * load the terrain stored in file filename to the memory
     * @param filename
     */
    void loadTerrain(std::string filename);

    block getBlockAt(Pair pos);

private:
    block ** terrain;
    const size_t width;
    const size_t height;
};


#endif //JEU2D_LEVEL_H

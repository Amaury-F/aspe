//
// Created by amaury on 23/02/18.
//

#ifndef JEU2D_LEVEL_H
#define JEU2D_LEVEL_H


#include <cstdlib>
#include <string>
#include "../environment/Blocks.h"
#include "../Pair.h"

/**
 * This class contains information on a level terrain :
 * the blocks contained in it and their position
 * the size of the level
 */
class Level {
public:
    Level(size_t w, size_t h);
    ~Level();

    /**
     * load the terrain stored in file filename to the memory
     * @param filename
     */
    void loadTerrain(std::string filename);

    /**
     * Get the block where position pos is in
     */
    block getBlockAt(Pair pos) const;

    Pair getSize() const;

    /**
     * get the block cell that contains pposition os
     */
    static Pair getCellOf(Pair pos);

private:
    block ** terrain;
    const size_t width;
    const size_t height;
};


#endif //JEU2D_LEVEL_H

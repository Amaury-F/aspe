//
// Created by amaury on 26/02/18.
//

#ifndef JEU2D_LEVELVIEW_H
#define JEU2D_LEVELVIEW_H


#include <cstdlib>
#include <string>
#include "../../model/Pair.h"
#include "Tiles.h"

/**
 * This class contains information on a level view :
 * the tiles contained in it and their position
 * the size of the level
 */
class LevelView {
public:
    LevelView(size_t w, size_t h);
    ~LevelView();

    /**
     * load the tiles stored in file filename to the memory
     * @param filename
     */
    void loadView(std::string filename);

    /**
     * Get the block where position pos is in
     */
    tile getTileAt(Pair pos) const;

    Pair getSize() const;

    /**
     * get the block cell that contains position pos
     */
    static Pair getCellOf(Pair pos);

private:
    tile ** terrain;
    const size_t width;
    const size_t height;
};


#endif //JEU2D_LEVELVIEW_H

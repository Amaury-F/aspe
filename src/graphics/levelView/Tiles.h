//
// Created by amaury on 26/02/18.
//

#ifndef JEU2D_TILES_H
#define JEU2D_TILES_H


typedef char tile;

class Tiles {
public:
    enum Tles {
        AIR = 0,
        DIRT = 1,
        STONE = 2,

        NBR_TILES = STONE + 1
    };

private:
    Tiles() = default;
    ~Tiles() = default;

};


#endif //JEU2D_TILES_H

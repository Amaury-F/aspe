//
// Created by amaury on 23/02/18.
//

#ifndef JEU2D_BLOCKS_H
#define JEU2D_BLOCKS_H

typedef char block;

class Blocks {
public:
    enum Blck {
        AIR = 0,
        GROUND = 1,
        WALL = 2,

        NBR_BLOCKS = WALL + 1
    };

private:
    Blocks() = default;
    ~Blocks() = default;

};


#endif //JEU2D_BLOCKS_H

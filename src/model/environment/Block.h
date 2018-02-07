//
// Created by amaury on 04/02/18.
//

#ifndef JEU2D_BLOCK_H
#define JEU2D_BLOCK_H


#include "../Pair.h"

//abstrait. mère de tous les blocs.
class Block {
protected:
    Block();

    explicit Block(Pair pos);
    ~Block();

    Pair pos;

private:
    //Chunk chunk;
};


#endif //JEU2D_BLOCK_H

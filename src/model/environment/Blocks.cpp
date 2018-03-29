#include "Blocks.h"
#include "../ModelConstants.h"

#define INF 5000

bool Blocks::isGround(block b) {
    return b >= Blocks::GROUND;
}

bool Blocks::isWall(block b) {
    return b >= Blocks::WALL;
}

bool Blocks::isAir(block b) {
    return b == 0;
}

bool Blocks::isUp(block b) {
    return (b >= Blocks::GROUND_SLOPENW1 && b <= Blocks::GROUND_SLOPENE5)
           || (b >= Blocks::WALL_SLOPENW1 && b <= Blocks::WALL_SLOPENE5);
}

bool Blocks::isDown(block b) {
    return (b >= Blocks::GROUND_SLOPESW1 && b <= Blocks::GROUND_SLOPESE5)
           || (b >= Blocks::WALL_SLOPESE1 && b <= Blocks::WALL_SLOPESE5);
}

bool Blocks::isSlope(block b) {
    return Blocks::isUp(b) || Blocks::isDown(b);
}

int Blocks::slope(int x, block b) {
    if (b == Blocks::GROUND_SLOPENW1 || b == Blocks::GROUND_SLOPESE1
            || b == Blocks::WALL_SLOPENW1 || b == Blocks::WALL_SLOPESE1) {
        return x;
    } else if (b == Blocks::GROUND_SLOPENE1 || b == Blocks::GROUND_SLOPESW1
            || b == Blocks::WALL_SLOPENE1 || b == Blocks::WALL_SLOPESW1) {
        return BLOCK_SIZE - x;
    } else if (b == Blocks::GROUND_SLOPENW3 || b == Blocks::GROUND_SLOPESE5
            || b == Blocks::WALL_SLOPENW3 || b == Blocks::WALL_SLOPESE5) {
        return x / 2;
    } else if (b == Blocks::GROUND_SLOPENE3 || b == Blocks:: GROUND_SLOPESW5
            || b == Blocks::WALL_SLOPENE3 || b == Blocks:: WALL_SLOPESW5) {
        return (BLOCK_SIZE - x) / 2;
    } else if (b == Blocks::GROUND_SLOPENW5 || b == Blocks::GROUND_SLOPESE3
            || b == Blocks::WALL_SLOPENW5 || b == Blocks::WALL_SLOPESE3) {
        return (BLOCK_SIZE + x) / 2;
    } else if (b == Blocks::GROUND_SLOPENE5 || b == Blocks::GROUND_SLOPESW3
            || b == Blocks::WALL_SLOPENE5 || b == Blocks::WALL_SLOPESW3) {
        return BLOCK_SIZE - (x / 2);
    } else if (b == Blocks::GROUND_SLOPENW4 || b == Blocks::WALL_SLOPENW4) {
        return x < BLOCK_SIZE / 2 ? 2 * x : BLOCK_SIZE;
    } else if (b == Blocks::GROUND_SLOPENE4 || b == Blocks::WALL_SLOPENE4) {
        return x <= BLOCK_SIZE / 2 ? BLOCK_SIZE : (BLOCK_SIZE - x) * 2;
    } else if (b == Blocks::GROUND_SLOPESW4 || b == Blocks::WALL_SLOPESW4) {
        return x < BLOCK_SIZE / 2 ? BLOCK_SIZE - 2 * x : 0;
    } else if (b == Blocks::GROUND_SLOPESE4 || b == Blocks::WALL_SLOPESE4) {
        return x < BLOCK_SIZE / 2 ? 0 :  2 * x - BLOCK_SIZE;
    } else if (b == Blocks::GROUND_SLOPENW2 || b == Blocks :: WALL_SLOPENW2) {
        return x < BLOCK_SIZE / 2 ? - INF : 2 * x - BLOCK_SIZE;
    } else if (b == Blocks::GROUND_SLOPENE2 || b == Blocks::WALL_SLOPENE2) {
        return x < BLOCK_SIZE / 2 ? BLOCK_SIZE - 2 * x : - INF;
    } else if (b == Blocks::GROUND_SLOPESW2 || b == Blocks::WALL_SLOPESW2) {
        return x < BLOCK_SIZE / 2 ? INF : (BLOCK_SIZE - x) * 2;
    } else if (b == Blocks::GROUND_SLOPESE2 || b == Blocks::WALL_SLOPESE2) {
        return x < BLOCK_SIZE / 2 ? BLOCK_SIZE - 2 * x : INF;
    }
}
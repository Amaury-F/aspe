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
        GROUND_SLOPENW1 = 2,
        GROUND_SLOPENW2 = 3,
        GROUND_SLOPENW3 = 4,
        GROUND_SLOPENW4 = 5,
        GROUND_SLOPENW5 = 6,
        GROUND_SLOPENE1 = 7,
        GROUND_SLOPENE2 = 8,
        GROUND_SLOPENE3 = 9,
        GROUND_SLOPENE4 = 10,
        GROUND_SLOPENE5 = 11,
        GROUND_SLOPESW1 = 12,
        GROUND_SLOPESW2 = 13,
        GROUND_SLOPESW3 = 14,
        GROUND_SLOPESW4 = 15,
        GROUND_SLOPESW5 = 16,
        GROUND_SLOPESE1 = 17,
        GROUND_SLOPESE2 = 18,
        GROUND_SLOPESE3 = 19,
        GROUND_SLOPESE4 = 20,
        GROUND_SLOPESE5 = 21,
        WALL = 22,
        WALL_SLOPENW1 = 23,
        WALL_SLOPENW2 = 24,
        WALL_SLOPENW3 = 25,
        WALL_SLOPENW4 = 26,
        WALL_SLOPENW5 = 27,
        WALL_SLOPENE1 = 28,
        WALL_SLOPENE2 = 29,
        WALL_SLOPENE3 = 30,
        WALL_SLOPENE4 = 31,
        WALL_SLOPENE5 = 32,
        WALL_SLOPESW1 = 33,
        WALL_SLOPESW2 = 34,
        WALL_SLOPESW3 = 35,
        WALL_SLOPESW4 = 36,
        WALL_SLOPESW5 = 37,
        WALL_SLOPESE1 = 38,
        WALL_SLOPESE2 = 39,
        WALL_SLOPESE3 = 40,
        WALL_SLOPESE4 = 41,
        WALL_SLOPESE5 = 42,

        NBR_BLOCKS = WALL_SLOPESE5 + 1
    };

    /**
     * Indique si b est un block de sol.
     */
    bool isGround(block b);

    /**
     * Indique si b est un block de mur.
     */
    bool isWall(block b);

    /**
     * Indique si b est un block de type pente et plafond.
     */
    bool isUp(block b);

    /**
     * Indique si b est un block de type pente et sol.
     */
    bool isDown(block b);

    /**
     * Indique si b est un block de type pente.
     */
    bool isSlope(block b);

    /**
     * On associe à chaque type de blocks une fonction représentant sa pente.
     * @pre
     *      0 <= x <= BLOCK_SIZE
     *      isSlope(b);
     */
    int slope(int x, block b);

private:
    Blocks() = default;
    ~Blocks() = default;

};


#endif //JEU2D_BLOCKS_H

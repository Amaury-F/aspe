#ifndef JEU2D_LEVEL_H
#define JEU2D_LEVEL_H


#include <cstdlib>
#include <string>
#include "../environment/Blocks.h"
#include "../Pair.h"

/**
 * Classe contenant toutes les informations relative au niveau courrant.
 */
class Level {
public:
    Level(size_t w, size_t h);
    ~Level();

    /**
     * Charge dans la mémoire le terrain(niveau) stocké dans le fichier filename.
     * @param filename
     */
    void loadTerrain(std::string filename);

    /**
     * Getter sur le block à la position pos.
     * @return blockAt
     */
    block getBlockAt(Pair pos) const;

    /**
     * Getter sur la taille du niveau.
     * @return levelSize
     */
    Pair getSize() const;

    /**
     * Getter sur la cellule qui contient la position pos.
     * @return cellPos
     */
    static Pair getCellOf(Pair pos);

private:
    block ** terrain;
    const size_t width;
    const size_t height;
};


#endif //JEU2D_LEVEL_H

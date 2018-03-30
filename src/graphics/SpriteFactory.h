#ifndef JEU2D_SPRITEFACTORY_H
#define JEU2D_SPRITEFACTORY_H

#include <vector>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <unordered_map>
#include "../model/player/Player.h"

class SpriteFactory {

public:
    SpriteFactory();
    ~SpriteFactory();

    /**
     * Crée et renvoie la sprite d'une entité.
     * @param entity
     * @return entitySprite*
     */
    sf::Sprite * create(const Player &entity);

    /**
     * Gère les sprites pour le joueur : est utilisé par create.
     * @param player
     * @param texture
     * @return playerSprite*
     */
    sf::Sprite * createFromPlayer(const Player &player, sf::Texture *texture);


private:

    std::unordered_map<std::string, sf::Texture *> textures;

};

#endif //JEU2D_SPRITEFACTORY_H

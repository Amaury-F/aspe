//
// Created by godarqu1 on 26/02/18.
//

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

    sf::Sprite * create(const Player &entity);
    sf::Sprite * createFromPlayer(const Player &player, sf::Texture *texture);


        private:
    std::unordered_map<std::string, sf::Texture *> textures;

};

#endif //JEU2D_SPRITEFACTORY_H

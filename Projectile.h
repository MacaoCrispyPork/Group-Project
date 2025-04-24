#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Entity.h"

class Projectile : public Entity
{
private:
    int damage;

public:
    Projectile();

    Projectile(int r, sf::Vector2f position, sf::Color Colour, int speed,
               sf::Vector2f destination, bool isPlayer, int damage);

    std::string getType();

    int getDamage();
};
#endif
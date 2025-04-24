#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Entity.h"

class Projectile : public Entity
{
protected:
    int damage;

public:
    Projectile();

    Projectile(int r, int x, int y, sf::Color color, int speed,
               float destinationX, float destinationY, bool isPlayer,
               int damage);

    std::string getType();

    int getDamage();
};
#endif
#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Entity.h"

class Projectile : public Entity
{
protected:
    int damage;

public:
    Projectile(int r, int x, int y, sf::Color color, int speed, float destinationX, float destinationY, bool isPlayer, int damage);

    Projectile();

    std::string getType();

    int Projectile::getDamage();
};
#endif
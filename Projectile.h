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
    //todo: color based on isPlayer
    Projectile(int r, int x, int y, sf::Color color, int speed, float destinationX, float destinationY, bool isPlayer, int damage) : Entity(r, x, y, color, speed, destinationX, destinationY, isPlayer), damage(damage) {}

    Projectile() : Projectile(0, 0, 0, sf::Color::Red, 0, 0, 0, NULL, 0) {}

    std::string getType() override
    {
        return "Projectile";
    }
    int getDamage()
    {
        return damage;
    }
};
#endif
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

    Projectile(int r, sf::Vector2f position, sf::Color Colour, float speed,
               sf::Vector2f destination, bool isPlayer, int damage);

    std::string getType() override;

    int getDamage();

    void handleCollision(Entity *entity);

    void move() override;
};
#endif
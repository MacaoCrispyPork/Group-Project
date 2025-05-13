#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Enemy.h"

class Skeleton : public Enemy
{
public:
    Skeleton();
    Skeleton(int r, sf::Vector2f position, int speed, int health, Weapon *weapon, int xp);
    std::optional<Projectile> updateAI(sf::Vector2f playerPosition) override;
};
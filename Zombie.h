#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Enemy.h"

class Zombie : public Enemy
{
public:
    Zombie();
    Zombie(int r, sf::Vector2f position, float speed, int health, Weapon *weapon, int xp);
    std::optional<Projectile> updateAI(sf::Vector2f playerPosition) override;
};
#endif
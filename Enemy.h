#ifndef ENEMY_H
#define ENEMY_H

#include "Weapon.h"
#include "Character.h"

class Enemy : public Character
{
protected:
    int xp;

public:
    Enemy();
    Enemy(int r, sf::Vector2f position, int speed, int health, Weapon *weapon, int xp);
    std::string getType() override;
    virtual std::optional<Projectile> updateAI(sf::Vector2f playerPosition) = 0;
};
#endif
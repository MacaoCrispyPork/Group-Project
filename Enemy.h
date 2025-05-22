#ifndef ENEMY_H
#define ENEMY_H

#include "Weapon.h"
#include "Character.h"

class Enemy : public Character
{
protected:
    int xp;
    float updateInterval;
    clock_t lastUpdate;

public:
    Enemy();
    Enemy(int r, sf::Vector2f position, float speed, int health, Weapon *weapon, int xp, float updateInterval);
    std::string getType() override;
    virtual std::optional<Projectile> updateAI(sf::Vector2f playerPosition) = 0;
};
#endif
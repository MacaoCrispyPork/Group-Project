#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projectile.h"
#include <ctime>
#include <optional>

class Weapon
{
protected:
    int damage;
    int fireRate;
    int projSize;
    int projSpeed;
    clock_t lastAttack;
    Projectile *projectile;

public:
    Weapon() : Weapon(0, 0, 0, 0) {}
    Weapon(int damage, int fireRate, int projSize, int projSpeed)
    {
        this->damage = damage;
        this->fireRate = fireRate;
        this->projSize = projSize;
        this->projSize = projSpeed;
        this->lastAttack = clock();
    }

    virtual std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) {};

    clock_t getLastAttack()
    {
        return lastAttack;
    }
    int getFireRate()
    {
        return fireRate;
    }
    //~Weapon();
};
#endif
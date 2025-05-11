#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <optional>

#include "Projectile.h"

class Weapon
{
protected:
    int damage;
    float fireRate;
    int projSize;
    int projSpeed;
    clock_t lastAttack;

public:
    Weapon();
    Weapon(int damage, float fireRate, int projSize, int projSpeed);

    virtual std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) = 0;

    clock_t getLastAttack();
    int getFireRate();
};
#endif
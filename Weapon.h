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
    int fireRate;
    int projSize;
    int projSpeed;
    clock_t lastAttack;
    Projectile *projectile;

public:
    Weapon();
    Weapon(int damage, int fireRate, int projSize, int projSpeed);

    virtual std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer);

    clock_t getLastAttack();
    int getFireRate();
};
#endif
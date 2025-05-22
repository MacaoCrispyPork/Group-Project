#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <optional>

#include "Projectile.h"

class Weapon
{
private:
    int damage;
    float fireRate;
    int projSize;
    float projSpeed;
    float range;
    clock_t lastAttack;

public:
    Weapon();
    Weapon(int damage, float fireRate, int projSize, float projSpeed, float range);

    std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer);
    clock_t getLastAttack();
    int getFireRate();
    sf::Vector2f calculateRange(sf::Vector2f position, sf::Vector2f destination);
};
#endif
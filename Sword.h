#ifndef SWORD_H
#define SWORD_H

#include <optional>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projectile.h"
#include <ctime>
#include <Weapon.h>

class Sword : public Weapon
{
public:
    Sword() : Sword(0, 0, 0, 0) {}
    Sword(int damage, int fireRate, int projSize, int projSpeed) : Weapon(damage, fireRate, projSize, projSpeed) {}

    std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) override
    {
        if (((float)(clock() - lastAttack) / CLOCKS_PER_SEC) > fireRate)
        {
            this->lastAttack = clock();
            return Projectile(projSize, position.x, position.y, sf::Color::Red, damage, projSpeed, position.x, position.y, isPlayer);
        }
        return std::nullopt;
    }
};
#endif
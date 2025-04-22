#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity.h"
#include "Weapon.h"

class Character : public Entity
{
protected:
    int health;
    Weapon *weapon;

public:
    Character(int r, int x, int y, sf::Color color, int speed, float destinationX, float destinationY, bool isPlayer, int health, Weapon *weapon) : Entity(r, x, y, color, speed, destinationX, destinationY, isPlayer), weapon(weapon), health(health) {}
    Character() : Character(0, 0, 0, sf::Color::Cyan, 0, 0, 0, NULL, 0, nullptr) {}

    Weapon *getWeapon()
    {
        return weapon;
    }

    void takeDamage(int damage)
    {
        this->health -= damage;
    }

    std::optional<Projectile> attack(sf::Vector2f destination)
    {
        return this->weapon->attack(this->getPosition(), destination, this->isPlayer);
    }
};
#endif
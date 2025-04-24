#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "Weapon.h"

class Character : public Entity
{
protected:
    int health;
    Weapon *weapon;

public:
    Character();

    Character(int r, int x, int y, sf::Color color, int speed,
              float destinationX, float destinationY, bool isPlayer,
              int health, Weapon *weapon);

    Weapon *getWeapon();

    void takeDamage(int damage);

    std::optional<Projectile> attack(sf::Vector2f destination);
};
#endif
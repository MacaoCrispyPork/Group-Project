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

    Character(int r, sf::Vector2f position, sf::Color color, float speed,
              bool isPlayer, int health, Weapon *weapon);

    Weapon *getWeapon();

    void takeDamage(int damage);
    
    int getHealth();

    void handleCollision(Projectile *projectile);

    std::optional<Projectile> attack(sf::Vector2f destination);

    ~Character();
};
#endif
#ifndef ENEMY_H
#define ENEMY_H

#include "Weapon.h"
#include "Character.h"
#include "Player.h"

class Enemy : public Character
{
protected:
    int xp;

public:
Enemy();
    Enemy(int r, sf::Vector2f position, int speed, int health, Weapon *weapon, int xp);
    void setPosition(Player *player);
    std::string getType();
    
    void takeDamage(int damage);

    std::optional<Projectile> attack(sf::Vector2f destination);
};
#endif
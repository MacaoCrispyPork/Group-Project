#ifndef SWORD_H
#define SWORD_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projectile.h"
#include <ctime>

class Sword : public Weapon
{
protected:
    
public:
    Sword();
    Sword(int damage, int fireRate, int projSize, int projSpeed) {
        this->damage = damage;
        this->fireRate = fireRate;
        this->projSize = projSize;
        this->projSize = projSpeed;
        this->lastAttack = clock();
    }
    Projectile attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) override{
        //if (((float)(clock()-lastAttack) / CLOCKS_PER_SEC) < fireRate) {
            this->lastAttack = clock();
            return Projectile(projSize,position.x,position.y,damage,projSpeed, destination.x, destination.y, isPlayer);
        //}
    }
    //~Sword();
};
#endif
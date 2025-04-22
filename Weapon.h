#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projectile.h"
#include <ctime>

class Weapon 
{
protected:
    int damage;
    int fireRate;
    int projSize;
    int projSpeed;
    clock_t lastAttack;
    Projectile* projectile;
public:
    Weapon() {
        damage = 0;
        fireRate = 0;
        projSpeed = 0;
        projSize = 0;
        lastAttack = clock();
    }
    Weapon(int damage, int fireRate, int projSize, int projSpeed) {
        this->damage = damage;
        this->fireRate = fireRate;
        this->projSize = projSize;
        this->projSize = projSpeed;
        this->lastAttack = clock();
    }
    virtual Projectile attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) = 0;


    clock_t getLastAttack() {
        return lastAttack;
    }
    int getFireRate() {
        return fireRate;
    }
    //~Weapon();
};
#endif
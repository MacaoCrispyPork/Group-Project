#ifndef BOW_H
#define BOW_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projectile.h"
#include "Weapon.h"

#include <ctime>

class Bow  : public Weapon
{
protected:
    int range;
public:
    Bow() {
        this->damage = 0;
        this->fireRate =0;
        this->lastAttack =clock();
        this->projSize = 0;
        this->projSpeed =0;
        this->range =0;

    }
    Bow(int damage, int fireRate, int projSize, int projSpeed, int range) {
        this->damage = damage;
        this->fireRate = fireRate;
        this->projSize = projSize;
        this->projSpeed = projSpeed;
        this->lastAttack = clock();
        this->range = range;
    }
    
    Projectile attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) override{
        this->lastAttack = clock();
        
        return Projectile(projSize,position.x,position.y,damage,projSpeed, destination.x, destination.y, range, isPlayer);        
    }
    //~Bow();
};
#endif
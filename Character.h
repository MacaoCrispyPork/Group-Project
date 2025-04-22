#ifndef CHARACTER_H
#define CHARACTER_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Entity.h"
#include "Weapon.h"
class Character : public Entity {
protected:
    int health;
    Weapon* weapon;
public:
        Character(int r, int x, int y, int health, Weapon* weapon) {
        body = new sf::CircleShape();
        this->weapon = weapon;
        this->health = health;
        body->setRadius(r);
        body->setPosition(x,y);
        body->setFillColor(sf::Color::Cyan);
        body->setOrigin(r/2,r/2);
        destination = body->getPosition();
    }
    Character() {
        body = new sf::CircleShape();
        this->weapon = NULL;
        this->health = 0; 
        body->setRadius(0);
        body->setPosition(0,0);
        body->setFillColor(sf::Color::Cyan);
        destination = sf::Vector2f(0.f,0.f);
    }


    Weapon* getWeapon() {
        return weapon;
    }
    
    void takeDamage(int damage) {
        this->health -= damage;
    }

    /*~Character() {
        delete body;
    }*/
};
#endif
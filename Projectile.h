#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Entity.h"
#include "Weapon.h"
class Projectile : public Entity {
protected:
    int damage;
public:
    Projectile(int r, int x, int y, int damage,int projSpeed,float DestinationX, float DestinationY, bool isPlayer) {
        body = new sf::CircleShape();
        this->damage = damage;
        this->isPlayer = isPlayer;
        this->speed = projSpeed;
        body->setRadius(r);
        body->setPosition(x,y);
        body->setFillColor(sf::Color::Cyan);
        body->setOrigin(r/2,r/2);
        destination = sf::Vector2f(DestinationX,DestinationY);
    }
    Projectile(int r, int x, int y, int damage,int projSpeed,int DestinationX, int DestinationY, int range, bool isPlayer) {
        body = new sf::CircleShape();
        this->damage = damage;
        this->speed = projSpeed;
        this->isPlayer = isPlayer;
        body->setRadius(r);
        body->setPosition(x,y);
        body->setFillColor(sf::Color::Blue);
        body->setOrigin(r/2,r/2);
        destination = sf::Vector2f(DestinationX,DestinationY);
    }
    Projectile() {
        body = new sf::CircleShape();
        this->damage = 0;
        body->setRadius(0);
        body->setPosition(0,0);
        body->setFillColor(sf::Color::Red);
        destination = sf::Vector2f(0.f,0.f);
    }


    std::string getType() {
        return "Projectile";
    }
    int getDamage() {
        return damage;
    }

};
#endif
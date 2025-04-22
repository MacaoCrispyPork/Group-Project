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

    void move(sf::Vector2f finish) {
        sf::Vector2f movement = finish - body->getPosition();
        if (movement.x != 0.f || movement.y != 0.f) {
            float length = std::sqrt(movement.x*movement.x + movement.y*movement.y);
            movement /= length;
            movement *= speed; 
        }
        if (std::sqrt((body->getPosition().x-finish.x)*(body->getPosition().x-finish.x)+(body->getPosition().y-finish.y)*(body->getPosition().y-finish.y)) > speed/2) {
            body->move(movement);
        }
    }
    std::string getType() {
        return "Projectile";
    }
    int getDamage() {
        return damage;
    }

};
#endif
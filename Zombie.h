#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
#include "Character.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class Zombie : public Enemy {
private:

public:
    Zombie(int r, int x, int y, int health, float speed, int xp, Weapon* weapon) {
        body = new sf::CircleShape();
        this->weapon = weapon;
        this->health = health;
        this->speed = speed;
        this->xp = xp;
        body->setRadius(r);
        body->setPosition(x,y);
        body->setFillColor(sf::Color::Green);
        body->setOrigin(r/2,r/2);
        destination = sf::Vector2f(0.f,0.f);
    }
    Zombie() {
        body = new sf::CircleShape();
        this->weapon = NULL;
        this->health = 0;
        this->speed = 0;
        this->xp = 0; 
        body->setRadius(0);
        body->setPosition(0,0);
        body->setFillColor(sf::Color::Cyan);
        destination = sf::Vector2f(0.f,0.f);
    }
    void setPosition(Player* player) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            destination = sf::Vector2f(player->getPosition().x,player->getPosition().y);
        }
    }
    sf::Vector2f getDestination() {
        return destination;
    }
    std::string getType() {
        return "Zombie";
    }
    /*
    ~Player();
    */
};
#endif
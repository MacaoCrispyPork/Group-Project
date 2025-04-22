#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
#include "Character.h"
#include "Entity.h"
class Player : public Character {
private:
    int level;
public:
    Player(int r, int x, int y, int health, int speed, Weapon* weapon) {
        body = new sf::CircleShape();
        this->weapon = weapon;
        this->health = health;
        this->speed = speed;
        this->isPlayer = 1;
        body->setRadius(r);
        body->setPosition(x,y);
        body->setFillColor(sf::Color::Cyan);
        body->setOrigin(r/2,r/2);
        destination = sf::Vector2f(0.f,0.f);
        level = 0;
    }
    Player() {
        body = new sf::CircleShape();
        this->weapon = weapon;
        this->health = health; 
        body->setRadius(0);
        body->setPosition(0,0);
        body->setFillColor(sf::Color::Cyan);
        destination = sf::Vector2f(0.f,0.f);
        level = 0;
    }
    void setPosition(sf::RenderWindow* win) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            destination = sf::Vector2f(sf::Mouse::getPosition(*win).x,sf::Mouse::getPosition(*win).y);
        }
    }
    sf::Vector2f getDestination() {
        return destination;
    }

    std::string getType() {
        return "Player";
    }
    /*
    ~Player();
    */
};
#endif
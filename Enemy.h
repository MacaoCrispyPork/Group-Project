#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
#include "Character.h"
#include "Player.h"
#include "Entity.h"
class Enemy : public Character
{
protected:
    int xp;

public:
    Enemy(int r, int x, int y, int speed, int health, Weapon *weapon, int xp) : Character(r, x, y, sf::Color::Green, speed, x, y, 1, health, weapon), xp(xp) {}
    Enemy() : Enemy(0, 0, 0, 0, 0, nullptr, 0) {}
    void setPosition(Player *player)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            destination = player->getPosition();
        }
    }
};
#endif
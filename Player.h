#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
#include "Character.h"
#include "Entity.h"
class Player : public Character
{
private:
    int level;

public:
    Player(int r, int x, int y, int speed, int health, Weapon *weapon) : Character(r, x, y, sf::Color::Cyan, speed, x, y, 1, health, weapon), level(0) {}
    Player() : Player(0, 0, 0, 0, 0, nullptr) {}
    void setPosition(sf::RenderWindow *win)
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            destination = sf::Vector2f(sf::Mouse::getPosition(*win).x, sf::Mouse::getPosition(*win).y);
        }
    }
    std::string getType() override
    {
        return "Player";
    }
};
#endif
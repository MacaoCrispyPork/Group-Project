#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Weapon.h"
#include "Character.h"
#include "Entity.h"

Player::Player() : Player(0, 0, 0, 0, 0, nullptr) {}

Player::Player(int r, int x, int y, int speed, int health, Weapon *weapon)
    : Character(r, x, y, sf::Color::Cyan, speed,x, y, 1, health, weapon),
      level(0) {}

void Player::setPosition(sf::RenderWindow *win)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        destination = sf::Vector2f(sf::Mouse::getPosition(*win).x, sf::Mouse::getPosition(*win).y);
    }
}

std::string Player::getType()
{
    return "Player";
}
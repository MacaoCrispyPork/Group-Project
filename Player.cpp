#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Weapon.h"
#include "Character.h"
#include "Entity.h"

Player::Player() : Player(0, sf::Vector2(0.f, 0.f), 0, 0, nullptr) {}

Player::Player(int r, sf::Vector2f position, float speed, int health, Weapon *weapon)
    : Character(r, position, sf::Color::Cyan, speed, true, health, weapon),
      level(0) {}

void Player::setDestination(sf::Vector2f destination)
{
    this->destination = destination;
}

std::string Player::getType()
{
    return "Player";
}

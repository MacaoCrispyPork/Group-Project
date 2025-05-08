#include "Enemy.h"
#include "Weapon.h"
#include "Character.h"
#include "Player.h"

Enemy::Enemy() : Enemy(0, sf::Vector2(0.f, 0.f), 0, 0, nullptr, 0) {}

Enemy::Enemy(int r, sf::Vector2f position, int speed, int health, Weapon *weapon, int xp)
    : Character(r, position, sf::Color::Green, speed, 1, health, weapon),
      xp(xp) {}

void Enemy::setPosition(Player *player)
{
    destination = player->getPosition();
}
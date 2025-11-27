#include "Enemy.h"
#include "Weapon.h"
#include "Character.h"
#include "Player.h"

Enemy::Enemy() : Enemy(0, sf::Vector2(0.f, 0.f), sf::Color::Black, 0, 0, nullptr, 0, 0) {}

Enemy::Enemy(int r, sf::Vector2f position, sf::Color color, float speed, int health, Weapon *weapon, int xp, float updateInterval)
    : Character(r, position, color, speed, false, health, weapon),
      xp(xp), updateInterval(updateInterval) {lastUpdate = clock();}

std::string Enemy::getType() { return "Enemy"; }

int Enemy::getxp() { return xp; }

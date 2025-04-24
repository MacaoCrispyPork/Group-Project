#include "Enemy.h"
#include "Weapon.h"
#include "Character.h"
#include "Player.h"

Enemy::Enemy(int r, int x, int y, int speed, int health, Weapon *weapon, int xp) : Character(r, x, y, sf::Color::Green, speed, x, y, 1, health, weapon), xp(xp) {}
Enemy::Enemy() : Enemy(0, 0, 0, 0, 0, nullptr, 0) {}
void Enemy::setPosition(Player *player)
{
    destination = player->getPosition();
}
std::string Enemy::getType() {
    return "Enemy";
}
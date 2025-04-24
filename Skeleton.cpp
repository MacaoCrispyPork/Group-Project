#include "Enemy.h"
#include "Skeleton.h"

Skeleton::Skeleton() : Skeleton(0, sf::Vector2f(0.f, 0.f), 0, 0, nullptr, 0) {}
Skeleton::Skeleton(int r, sf::Vector2f position, int speed, int health, Weapon *weapon, int xp)
    : Enemy(r, position, speed, health, weapon, xp) {}
std::string Skeleton::getType()
{
    return "Skeleton";
}
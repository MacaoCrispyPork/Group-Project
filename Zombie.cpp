#include "Enemy.h"
#include "Zombie.h"

Zombie::Zombie() : Zombie(0, 0, 0, 0, 0, nullptr, 0) {}
Zombie::Zombie(int r, int x, int y, int speed, int health, Weapon *weapon, int xp)
    : Enemy(r, x, y, speed, health, weapon, xp) {}

std::string Zombie::getType()
{
    return "Zombie";
}
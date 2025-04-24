#include "Zombie.h"

Zombie::Zombie(int r, int x, int y, int speed, int health, Weapon *weapon, int xp) : Enemy(r, x, y, speed, health, weapon, xp) {}
Zombie::Zombie() : Zombie(0, 0, 0, 0, 0, nullptr, 0) {}
std::string Zombie::getType()
{
    return "Zombie";
}
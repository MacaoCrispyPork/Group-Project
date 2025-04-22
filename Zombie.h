#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
#include "Character.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class Zombie : public Enemy
{
public:
    Zombie(int r, int x, int y, int speed, int health, Weapon *weapon, int xp) : Enemy(r, x, y, speed, health, weapon, xp) {}
    Zombie() : Zombie(0, 0, 0, 0, 0, nullptr, 0) {}
    std::string getType() override
    {
        return "Zombie";
    }
};
#endif
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Weapon.h"
#include "Enemy.h"

class Zombie : public Enemy
{
public:
    Zombie();
    Zombie(int r, int x, int y, int speed, int health, Weapon *weapon, int xp);
    std::string getType() override;
};
#endif
#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
#include "Character.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class Skeleton : public Enemy
{
public:
    Skeleton();
    Skeleton(int r, int x, int y, int speed, int health, Weapon *weapon, int xp);
    std::string getType() override;
};
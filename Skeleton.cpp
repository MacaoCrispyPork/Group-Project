#include <SFML/Graphics.hpp>
#include <cmath>
#include "Weapon.h"
#include "Character.h"
#include "Player.h"
#include "Entity.h"
#include "Enemy.h"
#include "Skeleton.h"

Skeleton::Skeleton() : Skeleton(0, 0, 0, 0, 0, nullptr, 0) {}
Skeleton::Skeleton(int r, int x, int y, int speed, int health, Weapon *weapon, int xp) : Enemy(r, x, y, speed, health, weapon, xp) {}

std::string Skeleton::getType()
{
    return "Skeleton";
}
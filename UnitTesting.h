#ifndef UNITTESTING_H
#define UNITTESTING_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "Character.h"
#include "Weapon.h"
#include "Projectile.h"
#include "Zombie.h"
#include "Skeleton.h"
#include <vector>
#include "Game.h"

class UnitTest
{
private:
    void testRange();
public:
    void runTest();
};
#endif
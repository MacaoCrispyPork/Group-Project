#ifndef UNITTESTING_H
#define UNITTESTING_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "Player.h"
#include "Character.h"
#include "Weapon.h"
#include "Projectile.h"
#include "Zombie.h"
#include "Skeleton.h"
#include "Game.h"

// Class for unit testing various components of the game
class UnitTest
{
private:
    // Test fuction for calculateRange function in Weapon class
    void testRange();

    // Test function for takeDamage and getHealth functions in Player class
    void testDamage();

    // Test function for handleCollision function in Character class
    void testHandleCollision();

    // Test function for move function in Entity class
    void testMove();

    // Test function for checkCollision function in Entity class
    void testCollision();

public:
    // Runs all unit tests
    void runTest();
};
#endif
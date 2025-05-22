#include "UnitTesting.h"
#include <iostream>
void UnitTest::runTest()
{
    UnitTest::testRange();
}

void UnitTest::testRange()
{
    Weapon *weapon = new Weapon(1, 1, 1, 1, 10);
    if (weapon->calculateRange(sf::Vector2f(0,0),sf::Vector2f(3,4)) != sf::Vector2f(6,8))
    {
        std::cout << "ERROR: Calculate Range Test 1 Failed!" << std::endl;
    }
    if (weapon->calculateRange(sf::Vector2f(0,0),sf::Vector2f(0,2)) != sf::Vector2f(0,10))
    {
        std::cout << "ERROR: Calculate Range Test 2 Failed" << std::endl;
    }
    if (weapon->calculateRange(sf::Vector2f(0,0),sf::Vector2f(0,2)) != sf::Vector2f(0,10))
    {
        std::cout << "ERROR: Calculate Range Test 3 Failed" << std::endl;
    }
    if (weapon->calculateRange(sf::Vector2f(-6,-8),sf::Vector2f(0,0)) != sf::Vector2f(0,0))
    {
        std::cout << "ERROR: Calculate Range Test 4 Failed" << std::endl;
    }
}

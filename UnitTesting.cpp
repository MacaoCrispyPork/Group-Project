#include "UnitTesting.h"
#include <iostream>
void UnitTest::runTest()
{
    UnitTest::testRange();
    UnitTest::testDamage();
    UnitTest::testHandleCollision();
    UnitTest::testMove();
    UnitTest::testCollision();
    std::cout << "All Tests Passed Successfully :)" << std::endl;
}

void UnitTest::testRange()
{
    Weapon *weapon = new Weapon(10, 1, 1, 1, 10);
    // Testing basic calculate range functionality
    if (weapon->calculateRange(sf::Vector2f(0, 0), sf::Vector2f(3, 4)) != sf::Vector2f(6, 8))
    {
        std::cout << "ERROR: Calculate Range Test 1 Failed!" << std::endl;
    }
    // Testing along the y-axis
    if (weapon->calculateRange(sf::Vector2f(0, 0), sf::Vector2f(0, 2)) != sf::Vector2f(0, 10))
    {
        std::cout << "ERROR: Calculate Range Test 2 Failed" << std::endl;
    }
    // Testing along the x-axis
    if (weapon->calculateRange(sf::Vector2f(0, 0), sf::Vector2f(2, 0)) != sf::Vector2f(10, 0))
    {
        std::cout << "ERROR: Calculate Range Test 3 Failed" << std::endl;
    }
    // Testing when the current position of the character is negative
    if (weapon->calculateRange(sf::Vector2f(-6, -8), sf::Vector2f(0, 0)) != sf::Vector2f(0, 0))
    {
        std::cout << "ERROR: Calculate Range Test 4 Failed" << std::endl;
    }
}

void UnitTest::testDamage()
{
    Weapon *weapon = new Weapon(1, 0, 1, 1, 10);
    Player *player = new Player(10, sf::Vector2f(0, 0), 3, 50, weapon);
    player->takeDamage(10);
    // Testing basic damage functionality
    if (player->getHealth() != 40 || player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 1 Failed!" << std::endl;
    }
    // Testing negative damage (health boost)
    player->takeDamage(-5);

    if (player->getHealth() != 45 || player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 2 Failed!" << std::endl;
    }
    // Testing situation where no damage is done
    player->takeDamage(0);

    if (player->getHealth() != 45 || player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 3 Failed!" << std::endl;
    }
    // Testing situation resulting in IsDestroyed becoming true
    player->takeDamage(50);

    if (player->getHealth() != -5 || !player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 4 Failed!" << std::endl;
    }
}

void UnitTest::testHandleCollision()
{
    Weapon *weapon = new Weapon(10, 0, 1, 1, 10);
    Weapon* weapon2 = new Weapon(10, 0, 1, 1, 10);
    Player *player = new Player(10, sf::Vector2f(0, 0), 3, 50, weapon);
    Zombie *zombie = new Zombie(10, sf::Vector2f(0, 0), 1, 10, weapon2, 1, 1);

    sf::Clock clock;
    std::optional<Projectile> attack = zombie->attack(sf::Vector2f(0, 0));
    if (attack.has_value())
    {
        player->handleCollision(new Projectile(attack.value()),clock);
    }
    // Testing a basic projectile hit against a player
    if (player->getHealth() != 40|| player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Handle Collision Test 1 Failed!" << std::endl;
    }

    if (attack.has_value())
    {
        player->handleCollision(new Projectile(attack.value()),clock);
        player->handleCollision(new Projectile(attack.value()),clock);
        player->handleCollision(new Projectile(attack.value()),clock);
        player->handleCollision(new Projectile(attack.value()),clock);
    }
    // Testing a fatal projectile hit against a player
    if (player->getHealth() != 0 || !player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Handle Collision Test 2 Failed!" << std::endl;
    }
    delete player;
    delete zombie;
}

void UnitTest::testMove()
{
    Weapon *weapon = new Weapon(1, 1, 1, 1, 10);
    Zombie *zombie = new Zombie(10, sf::Vector2f(0, 0), 1, 10, weapon, 1, 1);
    zombie->updateAI(sf::Vector2f(0, 0));
    // Testing the zombie moves away from its current position in a randomised direction
    if (zombie->getPosition() != sf::Vector2f(0, 0))
    {
        std::cout << "ERROR: Test Move Test 1 Failed!" << std::endl;
    }
    delete zombie;
}


void UnitTest::testCollision()
{
    Weapon* weapon1 = new Weapon(1, 1, 1, 1, 10);
    Weapon* weapon2 = new Weapon(1, 1, 1, 1, 10);
    Weapon* weapon3 = new Weapon(1, 1, 1, 1, 10);
    Zombie* zombie = new Zombie(10, sf::Vector2f(0, 0), 1, 10, weapon1, 1, 1);
    Player* player = new Player(10, sf::Vector2f(0, 0), 3, 50, weapon2);
    Player* player2 = new Player(10, sf::Vector2f(0, 100), 3, 50, weapon3);

    // Test 1: Should collide
    if (!player->checkCollision(zombie))
    {
        std::cout << "ERROR: Test Collision Test 1 Failed!" << std::endl;
    }

    // Test 2: Should NOT collide
    if (player2->checkCollision(zombie))
    {
        std::cout << "ERROR: Test Collision Test 2 Failed!" << std::endl;
    }

    delete zombie;
    delete player;
    delete player2;
}

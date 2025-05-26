#include "UnitTesting.h"
#include <iostream>
void UnitTest::runTest()
{
    UnitTest::testRange();
    UnitTest::testDamage();
    UnitTest::testHandleCollision();
    UnitTest::testMove();
    UnitTest::testCollision();
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
    Weapon *weapon = new Weapon(1, 1, 1, 1, 10);
    Player *player = new Player(10, sf::Vector2f(0, 0), 3, 50, weapon);
    player->takeDamage(10);
    // Testing basic damage functionality
    if (player->getHealth() != 40 && !player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 1 Failed!" << std::endl;
    }
    // Testing negative damage (health boost)
    player->takeDamage(-5);

    if (player->getHealth() != 45 && !player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 2 Failed!" << std::endl;
    }
    // Testing situation where no damage is done
    player->takeDamage(0);

    if (player->getHealth() != 45 && !player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 3 Failed!" << std::endl;
    }
    // Testing situation resulting in IsDestroyed becoming true
    player->takeDamage(50);

    if (player->getHealth() != -5 && player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Damage Test 4 Failed!" << std::endl;
    }
}

void UnitTest::testHandleCollision()
{
    Weapon *weapon = new Weapon(10, 1, 1, 1, 10);
    Player *player = new Player(10, sf::Vector2f(0, 0), 3, 50, weapon);
    player->takeDamage(10);
    std::optional<Projectile> attack = player->attack(sf::Vector2f(0, 0));
    if (attack.has_value())
    {
        player->handleCollision(new Projectile(attack.value()));
    }
    // Testing a basic projectile hit against a player
    if (player->getHealth() != 40)
    {
        std::cout << "ERROR: Test Handle Collision Test 1 Failed!" << std::endl;
    }

    if (attack.has_value())
    {
        player->handleCollision(new Projectile(attack.value()));
        player->handleCollision(new Projectile(attack.value()));
        player->handleCollision(new Projectile(attack.value()));
        player->handleCollision(new Projectile(attack.value()));
        player->handleCollision(new Projectile(attack.value()));
    }
    // Testing a fatal projectile hit against a player
    if (player->getHealth() != -10 && player->getIsDestroyed())
    {
        std::cout << "ERROR: Test Handle Collision Test 2 Failed!" << std::endl;
    }
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
}

void UnitTest::testCollision()
{
    Weapon *weapon = new Weapon(1, 1, 1, 1, 10);
    Zombie *zombie = new Zombie(10, sf::Vector2f(0, 0), 1, 10, weapon, 1, 1);
    Player *player = new Player(10, sf::Vector2f(0, 0), 3, 50, weapon);
    // Testing if two coincident entities will collide
    if (!player->checkCollision(zombie))
    {
        std::cout << "ERROR: Test Collision Test 1 Failed!" << std::endl;
    }
    Player *player2 = new Player(10, sf::Vector2f(0, 100), 3, 50, weapon);
    // Testing if two non colliding entities will not collide
    if (player2->checkCollision(zombie))
    {
        std::cout << "ERROR: Test Collision Test 2 Failed!" << std::endl;
    }
}
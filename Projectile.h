#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Entity.h"

// Class representing a projectile in the game
class Projectile : public Entity
{
private:
    int damage; // Damage dealt by the projectile

public:
    // Default constructor
    Projectile();

    // Parameterized constructor
    // Inputs: radius, position, color, speed, destination, isPlayer, damage
    Projectile(int r, sf::Vector2f position, sf::Color Colour, float speed,
               sf::Vector2f destination, bool isPlayer, int damage);

    // Returns "projectile"
    // Output: string "projectile"
    std::string getType() override;

    // Returns the damage dealt by the projectile
    // Output: damage value
    int getDamage();

    // Handles collision with another entity
    // Inputs: pointer to another Entity object
    void handleCollision(Entity *entity);

    // Moves the projectile towards its destination by speed units
    // Overrides the move function from Entity, marking the projectile for destruction if it reaches its destination
    void move() override;
};
#endif
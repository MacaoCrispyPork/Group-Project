#ifndef CHARACTER_H
#define CHARACTER_H

#include "Entity.h"
#include "Weapon.h"

// Virtual class used for both player and enemies
class Character : public Entity
{
protected:
    int health;     // Health of the character
    Weapon *weapon; // The weapon held by the character

public:
    // Default constructor
    Character();

    // Parameterized constructor
    // Inputs: radius, position, color, speed, isPlayer, health, weapon
    Character(int r, sf::Vector2f position, sf::Color color, float speed,
              bool isPlayer, int health, Weapon *weapon);

    // Returns pointer to character's weapon
    // Output: pointer to Weapon object
    Weapon *getWeapon();

    // Returns the character's current health
    // Output: current health
    int getHealth();

    // Decrements health by damage amount
    // Inputs: damage
    void takeDamage(int damage);

    // Checks if character collides with a projectile, decreases health if so
    // Inputs: pointer to Projectile object
    void handleCollision(Projectile *projectile);

    // Attacks from character's position to target destination using the character's weapon
    // Inputs: destination (target position)
    // Output: optional Projectile if attack is possible, otherwise std::nullopt
    std::optional<Projectile> attack(sf::Vector2f destination);

    // Destructor
    ~Character();
};
#endif
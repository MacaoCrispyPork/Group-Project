#ifndef ENEMY_H
#define ENEMY_H

#include "Weapon.h"
#include "Character.h"

// Virtual class used for enemy characters in the game
class Enemy : public Character
{
protected:
    int xp;               // Experience points awarded for defeating the enemy
    float updateInterval; // Time between AI updates
    clock_t lastUpdate;   // Last time the AI was updated

public:
    // Default constructor
    Enemy();

    // Parameterized constructor
    // Inputs: radius, position, speed, health, weapon, xp, updateInterval
    Enemy(int r, sf::Vector2f position, sf::Color color, float speed, int health, Weapon *weapon, int xp, float updateInterval);

    // Returns "enemy"
    // Output: string "enemy"
    std::string getType() override;

    // Pure virtual function: updates the AI of the enemy and returns a projectile if it attacks
    // Input: playerPosition (current position of the player)
    // Output: optional Projectile if attack occurs, otherwise std::nullopt
    // This function must be implemented by derived classes (enemy types)
    virtual std::optional<Projectile> updateAI(sf::Vector2f playerPosition) = 0;

    // Returns the experience points awarded for defeating the enemy
    // Output: experience points
    int getxp();
};
#endif
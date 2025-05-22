#pragma once
#include "Enemy.h"

class Skeleton : public Enemy
{
public:
    // Default constructor for Skeleton
    Skeleton();

    // Parameterized constructor for Skeleton
    // Inputs: r (radius), position (spawn position), health, weapon (pointer), xp (experience), updateInterval (AI update interval)
    // Output: Skeleton object
    Skeleton(int r, sf::Vector2f position, int health, Weapon *weapon, int xp, float updateInterval);

    // Updates the AI for the skeleton and returns a projectile if it attacks
    // Input: playerPosition (current position of the player)
    // Output: optional Projectile if attack occurs
    std::optional<Projectile> updateAI(sf::Vector2f playerPosition) override;
};
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Enemy.h"

class Zombie : public Enemy
{
public:
    // Default constructor for Zombie
    Zombie();

    // Parameterized constructor for Zombie
    // Inputs: r (radius), position (spawn position), speed, health, weapon (pointer), xp (experience), updateInterval (AI update interval)
    // Output: Zombie object
    Zombie(int r, sf::Vector2f position, float speed, int health, Weapon *weapon, int xp, float updateInterval);

    // Updates the AI for the zombie and returns a projectile if it attacks
    // Input: playerPosition (current position of the player)
    // Output: optional Projectile if attack occurs
    std::optional<Projectile> updateAI(sf::Vector2f playerPosition) override;
};

#endif
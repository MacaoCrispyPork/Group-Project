#ifndef WEAPON_H
#define WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <ctime>
#include <optional>

#include "Projectile.h"

class Weapon
{
protected:
    int damage;           // Damage dealt by the weapon
    float fireRate;       // Minimum time between attacks (seconds)
    int projSize;         // Size of the projectile
    float projSpeed;      // Speed of the projectile
    float range;          // Maximum range of the weapon
    clock_t lastAttack;   // Time of last attack

public:
    // Default constructor
    Weapon();

    // Parameterized constructor
    // Inputs: damage, fireRate, projSize, projSpeed, range
    Weapon(int damage, float fireRate, int projSize, float projSpeed, float range);

    // Attempts to attack in the direction of destination
    // Inputs: position (start), destination (target), isPlayer (true if player)
    // Output: optional Projectile if attack is possible
    std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer);

    // Calculates the endpoint of a projectile based on range
    // Inputs: position (start), destination (target)
    // Output: endpoint vector
    sf::Vector2f calculateRange(sf::Vector2f position, sf::Vector2f destination);
};
#endif
#include <optional>
#include <iostream>
#include "Weapon.h"

Weapon::Weapon() : Weapon(0, 0, 0, 0, 0) {}

sf::SoundBuffer Weapon::sharedBuffer;
bool Weapon::bufferLoaded = false;


Weapon::Weapon(int damage, float fireRate, int projSize, float projSpeed, float range)
    : damage(damage),
      fireRate(fireRate),
      projSize(projSize), 
      projSpeed(projSpeed),
      range(range)
{
    this->lastAttack = clock();
    if (!bufferLoaded)
    {
        sharedBuffer.loadFromFile("click.wav");
    }
    sound.setBuffer(sharedBuffer);
}

sf::Vector2f Weapon::calculateRange(sf::Vector2f position, sf::Vector2f destination)
{
    // Calculate the direction vector from position to destination
    sf::Vector2f direction = destination - position;
    // Normalize the direction vector
    // If the length is zero, return the position (no movement)
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction /= length;
    }
    // Scale the direction vector by the range of the weapon
    return direction * range + position;
}

std::optional<Projectile> Weapon::attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer)
{
    // Check if enough time has passed since the last attack
    if (((float)(clock() - lastAttack) / CLOCKS_PER_SEC) < fireRate)
    {
        return std::nullopt;
    }
    sound.play();
    // Update the last attack time
    this->lastAttack = clock();
    // Calculate the endpoint of the projectile based on the range
    sf::Vector2f endpoint = calculateRange(position, destination);
    // compared to Weapon the endpoint = destination
    return std::optional<Projectile>{Projectile(projSize, position, sf::Color::Red, projSpeed, endpoint, isPlayer, damage)};
}

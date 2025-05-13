#include <optional>
#include <iostream>
#include "Weapon.h"

Weapon::Weapon() : Weapon(0, 0, 0, 0, 0) {}

Weapon::Weapon(int damage, float fireRate, int projSize, float projSpeed, int range)
    : damage(damage),
      fireRate(fireRate),
      projSize(projSize), 
      projSpeed(projSpeed),
      range(range)
{
    this->lastAttack = clock();
}

sf::Vector2f Weapon::calculateRange(sf::Vector2f position, sf::Vector2f destination)
{
    sf::Vector2f direction = destination - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction /= length;
    }
    return position + direction * static_cast<float>(range);
}

std::optional<Projectile> Weapon::attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer)
{
    if (((float)(clock() - lastAttack) / CLOCKS_PER_SEC) < fireRate)
    {
        return std::nullopt;
    }

    this->lastAttack = clock();
    sf::Vector2f endpoint = calculateRange(position, destination);
    // compared to Weapon the endpoint = destination
    return std::optional<Projectile>{Projectile(projSize, position, sf::Color::Red, projSpeed, endpoint, isPlayer, damage)};
}

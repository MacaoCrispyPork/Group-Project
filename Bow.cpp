#include "Bow.h"

Bow::Bow(int damage, int fireRate, int projSize, int projSpeed, int range) : Weapon(damage, fireRate, projSize, projSpeed), range(range) {}
Bow::Bow() : Bow(0, 0, 0, 0, 0) {}

sf::Vector2f Bow::calculateRange(sf::Vector2f position, sf::Vector2f destination, int range)
{
    sf::Vector2f direction = destination - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (length != 0)
    {
        direction /= length;
    }
    return position + direction * static_cast<float>(range);
}

std::optional<Projectile> Bow::attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer)
{
    if (((float)(clock() - lastAttack) / CLOCKS_PER_SEC) > fireRate)
    {
        this->lastAttack = clock();
        sf::Vector2f endpoint = calculateRange(position, destination, range);
        return Projectile(projSize, position.x, position.y, sf::Color::Red, damage, projSpeed, endpoint.x, endpoint.y, isPlayer);
    }
    return std::nullopt;
}
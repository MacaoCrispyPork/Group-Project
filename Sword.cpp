#include "Sword.h"

Sword::Sword() : Sword(0, 0, 0, 0) {}
Sword::Sword(int damage, float fireRate, int projSize, int projSpeed)
    : Weapon(damage, fireRate, projSize, projSpeed) {}

std::optional<Projectile> Sword::attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer)
{
    if (((float)(clock() - lastAttack) / CLOCKS_PER_SEC) > fireRate)
    {
        this->lastAttack = clock();
        // compared to Bow the destination = endpoint
        return Projectile(projSize, position, sf::Color::Red, projSpeed, destination, isPlayer, damage);
    }
    return std::nullopt;
}
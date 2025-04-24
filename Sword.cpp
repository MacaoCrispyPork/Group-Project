#include "Sword.h"

Sword::Sword() : Sword(0, 0, 0, 0) {}
Sword::Sword(int damage, int fireRate, int projSize, int projSpeed)
    : Weapon(damage, fireRate, projSize, projSpeed) {}

std::optional<Projectile> Sword::attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer)
{
    if (((float)(clock() - lastAttack) / CLOCKS_PER_SEC) > fireRate)
    {
        this->lastAttack = clock();
        return Projectile(projSize, position.x, position.y, sf::Color::Red, damage, projSpeed, position.x, position.y, isPlayer);
    }
    return std::nullopt;
}
#include "Skeleton.h"

Skeleton::Skeleton() : Skeleton(0, sf::Vector2f(0.f, 0.f), 0, 0, nullptr, 0, 0) {}
Skeleton::Skeleton(int r, sf::Vector2f position, float speed, int health, Weapon *weapon, int xp, float updateInterval)
    : Enemy(r, position, speed, health, weapon, xp, updateInterval) {}

std::optional<Projectile> Skeleton::updateAI(sf::Vector2f playerPosition) {
    return attack(playerPosition);
}
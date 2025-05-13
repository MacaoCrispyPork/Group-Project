#include "Enemy.h"
#include "Zombie.h"

Zombie::Zombie() : Zombie(0, sf::Vector2(0.f, 0.f), 0, 0, nullptr, 0) {}
Zombie::Zombie(int r, sf::Vector2f position, int speed, int health, Weapon *weapon, int xp)
    : Enemy(r, position, speed, health, weapon, xp) {}

std::optional<Projectile> Zombie::updateAI(sf::Vector2f playerPosition) {
    destination = playerPosition;
    return attack(destination);
}
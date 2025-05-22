#include "Enemy.h"
#include "Zombie.h"
#include <random>

Zombie::Zombie() : Zombie(0, sf::Vector2(0.f, 0.f), 0, 0, nullptr, 0, 0) {}
Zombie::Zombie(int r, sf::Vector2f position, float speed, int health, Weapon *weapon, int xp, float updateInterval)
    : Enemy(r, position, speed, health, weapon, xp, updateInterval) {}

std::optional<Projectile> Zombie::updateAI(sf::Vector2f playerPosition) {
    if (((float)(clock() - lastUpdate) / CLOCKS_PER_SEC) < updateInterval)
    {
        return std::nullopt;
    }

    this->lastUpdate = clock();

    float maxOffset = 50.f;
    static std::default_random_engine engine(std::random_device{}());
    std::uniform_real_distribution<float> dist(-maxOffset, maxOffset);
    sf::Vector2f offset(dist(engine), dist(engine));
    destination = playerPosition + offset;
    return attack(playerPosition);
}
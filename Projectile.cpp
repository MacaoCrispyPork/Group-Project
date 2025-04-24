#include "Projectile.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <cmath>

// todo: color based on isPlayer
Projectile::Projectile() : Projectile(0, sf::Vector2(0.f, 0.f), sf::Color::Red, 0, sf::Vector2(0.f, 0.f), NULL, 0) {}

Projectile::Projectile(int r, sf::Vector2f position, sf::Color color, int speed,
                       sf::Vector2f destination, bool isPlayer, int damage)
    : Entity(r, position, color, speed, destination, isPlayer),
      damage(damage) {}

std::string Projectile::getType()
{
    return "Projectile";
}

int Projectile::getDamage()
{
    return damage;
}
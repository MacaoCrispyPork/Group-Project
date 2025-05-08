#include "Projectile.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <cmath>

// todo: color based on isPlayer
Projectile::Projectile() : Projectile(0, sf::Vector2(0.f, 0.f), sf::Color::Black, 0, sf::Vector2(0.f, 0.f), false, 0) {}

Projectile::Projectile(int r, sf::Vector2f position, sf::Color Colour, int speed,
                       sf::Vector2f destination, bool isPlayer, int damage)
    : Entity(r, position, isPlayer ? sf::Color::Cyan : sf::Color::Red,
             speed, destination, isPlayer),
      damage(damage) {}

std::string Projectile::getType()
{
    return "Projectile";
}

int Projectile::getDamage()
{
    return damage;
}

void Projectile::move(){
    Entity::move();
    sf::Vector2f distance = getPosition() - destination;
    if (std::sqrt(distance.x*distance.x + distance.y*distance.y) < speed/2)
    {
        isDestroyed = true;
    }
}
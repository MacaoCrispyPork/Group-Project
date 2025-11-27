#include "Projectile.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

Projectile::Projectile() : Projectile(0, sf::Vector2(0.f, 0.f), sf::Color::Black, 0, sf::Vector2(0.f, 0.f), false, 0) {}

// Or statement to change the colour depending on if the projectile is a player or not
Projectile::Projectile(int r, sf::Vector2f position, sf::Color Colour, float speed,
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
    // If the projectile is close enough to its destination, destroy it
    if (std::sqrt(distance.x*distance.x + distance.y*distance.y) < speed/2)
    {
        isDestroyed = true;
    }
}

void Projectile::handleCollision(Entity *entity) {
    // Destroy projectile if it collides with any entity of different isPlayer status
    if(Entity::checkCollision(entity)) {
        isDestroyed = true;
    }
}
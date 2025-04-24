#include "Projectile.h"
#include <SFML/Graphics.hpp>
#include <cmath>

//todo: color based on isPlayer
Projectile::Projectile(int r, int x, int y, sf::Color color, int speed, float destinationX, float destinationY, bool isPlayer, int damage) : Entity(r, x, y, color, speed, destinationX, destinationY, isPlayer), damage(damage) {}

Projectile::Projectile() : Projectile(0, 0, 0, sf::Color::Red, 0, 0, 0, NULL, 0) {}

std::string Projectile::getType()
{
    return "Projectile";
}

int Projectile::getDamage()
{
    return damage;
}
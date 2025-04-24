#include "Character.h"

Character::Character(int r, int x, int y, sf::Color color, int speed, float destinationX, float destinationY, bool isPlayer, int health, Weapon *weapon) : Entity(r, x, y, color, speed, destinationX, destinationY, isPlayer), weapon(weapon), health(health) {}
Character::Character() : Character(0, 0, 0, sf::Color::Cyan, 0, 0, 0, NULL, 0, nullptr) {}

Weapon *Character::getWeapon()
{
    return weapon;
}

void Character::takeDamage(int damage)
{
    this->health -= damage;
}

std::optional<Projectile> Character::attack(sf::Vector2f destination)
{
    return this->weapon->attack(this->getPosition(), destination, this->isPlayer);
}
#include "Character.h"
#include "Entity.h"
#include "Weapon.h"

Character::Character() : Character(0, sf::Vector2(0.f, 0.f), sf::Color::Cyan, 0, NULL, 0, nullptr) {}

Character::Character(int r, sf::Vector2f position, sf::Color color, int speed,
                     bool isPlayer, int health, Weapon *weapon)
    : Entity(r, position, color, speed,
             position, isPlayer),
      weapon(weapon),
      health(health) {}

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
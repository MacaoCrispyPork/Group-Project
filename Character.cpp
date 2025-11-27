#include "Character.h"
#include "Entity.h"
#include "Weapon.h"
#include <iostream>

Character::Character() : Character(0, sf::Vector2(0.f, 0.f), sf::Color::Cyan, 0, false, 0, nullptr) {}

Character::Character(int r, sf::Vector2f position, sf::Color color, float speed,
                     bool isPlayer, int health, Weapon *weapon)
    : Entity(r, position, color, speed,
             position, isPlayer),
      weapon(weapon),
      health(health) 
      {
        this->color = color;
        this->lastHit = -1000.0f;
      }

Weapon *Character::getWeapon()
{
    return weapon;
}

void Character::takeDamage(int damage)
{
    this->health -= damage;
    if (health <= 0)
    {
        this->isDestroyed = true;
    }
}

int Character::getHealth()
{
    return this->health;
}

std::optional<Projectile> Character::attack(sf::Vector2f destination)
{
    return this->weapon->attack(this->getPosition(), destination, this->isPlayer);
}

Character::~Character()
{
    delete weapon;
}



void Character::handleCollision(Projectile *projectile, sf::Clock hitTime)
{
    if (Entity::checkCollision(projectile))
    {
        lastHit = hitTime.getElapsedTime().asSeconds();
        takeDamage(projectile->getDamage());
    }
}



void Character::updateFlash(sf::Clock clock)
{
    float elapsed = clock.getElapsedTime().asSeconds();
    if (elapsed - lastHit < 0.2f)
        body->setFillColor(sf::Color::Red);
    else
        body->setFillColor(color);
}
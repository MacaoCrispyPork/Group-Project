#include "Weapon.h"

Weapon::Weapon() : Weapon(0, 0, 0, 0) {}

Weapon::Weapon(int damage, int fireRate, int projSize, int projSpeed)
    : damage(damage),
      fireRate(fireRate), 
      projSize(projSize), 
      projSpeed(projSpeed) 
{
    this->lastAttack = clock();
}

std::optional<Projectile> Weapon::attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) {};

clock_t Weapon::getLastAttack()
{
    return lastAttack;
}
int Weapon::getFireRate()
{
    return fireRate;
}
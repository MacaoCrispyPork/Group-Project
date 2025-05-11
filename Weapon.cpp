#include <optional>

#include "Weapon.h"

Weapon::Weapon() : Weapon(0, 0, 0, 0) {}

Weapon::Weapon(int damage, float fireRate, int projSize, int projSpeed)
    : damage(damage),
      fireRate(fireRate),
      projSize(projSize), 
      projSpeed(projSpeed) 
{
    this->lastAttack = clock();
}

clock_t Weapon::getLastAttack()
{
    return lastAttack;
}

int Weapon::getFireRate()
{
    return fireRate;
}
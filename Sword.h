#ifndef SWORD_H
#define SWORD_H

#include <optional>
#include "Projectile.h"
#include "Weapon.h"

class Sword : public Weapon
{
public:
    Sword();
    Sword(int damage, int fireRate, int projSize, int projSpeed);
    std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) override;
};
#endif
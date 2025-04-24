#ifndef BOW_H
#define BOW_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Projectile.h"
#include "Weapon.h"
#include <optional>
#include <ctime>

class Bow : public Weapon
{
private:
    int range;

public:
    Bow();
    Bow(int damage, int fireRate, int projSize, int projSpeed, int range);
    sf::Vector2f calculateRange(sf::Vector2f position, sf::Vector2f destination, int range);
    std::optional<Projectile> attack(sf::Vector2f position, sf::Vector2f destination, bool isPlayer) override;
};
#endif

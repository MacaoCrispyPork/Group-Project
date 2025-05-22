#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Weapon.h"
#include "Character.h"
#include "Entity.h"

class Player : public Character
{
private:
    int level;

public:
    Player();
    Player(int r, sf::Vector2f position, float speed, int health, Weapon *weapon);
    void setDestination(sf::Vector2f destination);
    std::string getType() override;
};
#endif
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
    Player(int r, int x, int y, int speed, int health, Weapon *weapon);
    void setPosition(sf::RenderWindow *win);
    std::string getType() override;
};
#endif
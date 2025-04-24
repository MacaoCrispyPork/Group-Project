#ifndef ENEMY_H
#define ENEMY_H
#include "Weapon.h"
#include "Character.h"
#include "Player.h"
class Enemy : public Character
{
protected:
    int xp;

public:
    Enemy(int r, int x, int y, int speed, int health, Weapon *weapon, int xp);
    Enemy();
    void setPosition(Player *player);
    std::string getType();
};
#endif
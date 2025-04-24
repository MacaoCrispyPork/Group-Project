#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "Player.h"
#include "Character.h"
#include "Entity.h"
#include "Weapon.h"
#include "Bow.h"
#include "Projectile.h"
#include "Sword.h"
#include "Zombie.h"

class Game
{
private:
    sf::RenderWindow *win;
    Player *player;
    Weapon *weapon;
    Character **all_characters;
    Projectile **all_projectile;
    int projectileCount;

public:
    Game(int sizeX, int sizeY, std::string title);
    void run();
    ~Game();
};
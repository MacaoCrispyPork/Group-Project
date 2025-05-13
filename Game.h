#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.h"
#include "Character.h"
#include "Weapon.h"
#include "Projectile.h"
#include "Zombie.h"
#include "Skeleton.h"

class Game
{
private:
    sf::RenderWindow *win;
    Player *player;
    Character **all_characters;
    Projectile **all_projectiles;
    int projectileCount;

public:
    Game(int sizeX, int sizeY, std::string title);
    void run();
    bool handleEvents();
    void handlePlayerAttack();
    void updateGameState();
    void moveCharacters();
    void moveProjectiles();
    void handleCharacterCollisions();
    void handleProjectileCollisions();
    void deleteDestroyedEntities();
    void render();
    ~Game();
};
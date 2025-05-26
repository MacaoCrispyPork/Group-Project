#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
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
    std::vector<Enemy *> all_enemies;
    std::vector<Projectile *> all_projectiles;
    float score;
    sf::Clock clock;
    float lastTime;
    int wave;

public:
    Game(int sizeX, int sizeY, std::string title, Weapon weapon);
    bool run();
    void handleEvents();
    void handlePlayerAttack();
    void updateGameState();
    void moveEntities();
    void handleCollisions();
    void deleteDestroyedEntities();
    void updateAI();
    void render();
    void spawnWaveEnemies(int wave, int sizeX, int sizeY);
    ~Game();
};

#endif
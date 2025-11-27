#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Button.h"
#include "Player.h"
#include "Character.h"
#include "Weapon.h"
#include "Projectile.h"
#include "Zombie.h"
#include "Skeleton.h"

// Class representing the game state and logic
class Game
{
private:
    sf::RenderWindow *win;
    Player *player; // Pointer to the player object
    std::vector<Enemy *> all_enemies; // Vector containing pointers to all enemies which currently exist
    std::vector<Projectile *> all_projectiles; // Vector containing pointers to all projectiles which currently exist
    int score; // Current score of the user
    sf::Clock clock; // Clock used in decoupling game logic from rendering
    sf::Clock gameTime; // Global game time
    int wave; // Tracking the current wave of the game
    sf::Font font; // Font for the text boxes used in the game
    Button scoreCounter; // Button for displaying the players score
    Button healthCounter; // Button for displaying the players health


public:
    // Constructor
    // Inputs: window width, window height, title (window title), weapon (player's weapon)
    Game(int sizeX, int sizeY, std::string title, Weapon weapon);

    // Loops through the game logic until game ends or window is closed
    // Output: true if the player dies, false if window is closed
    bool run();
    void handleEvents();
    void handlePlayerAttack();

    // Updates the game state by moving entities, handling collisions, and updating AI
    void updateGameState();

    // Moves all entities in the game
    void moveEntities();

    // Handles collisions between projectiles and characters
    void handleCollisions();

    // Updates the character colour to be red when hurt
    void updateVisuals();

    // Deletes entities that are marked for destruction
    void deleteDestroyedEntities();

    // Updates the AI of all enemies
    void updateAI();

    // Displays entities to the window
    void render();

    // Spawns a wave of enemies based on the current wave number
    void spawnWaveEnemies(int wave, int sizeX, int sizeY);

    // Used to update the menu score
    float getScore();

    // Destructor
    ~Game();
};

#endif
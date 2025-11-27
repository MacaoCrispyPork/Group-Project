#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>

#include "Weapon.h"
#include "Character.h"
#include "Entity.h"

// Class representing the player character in the game
class Player : public Character
{
private:
    int level; // Player's level, used for experience and progression

public:
    // Default constructor
    Player();

    // Parameterized constructor
    // Inputs: radius, position, speed, health, weapon
    Player(int r, sf::Vector2f position, float speed, int health, Weapon *weapon);

    // Sets the player's destination for movement
    // Input: destination (target position)
    void setDestination(sf::Vector2f destination);

    // Returns "player"
    // Output: string "player"
    std::string getType() override;
    
};
#endif
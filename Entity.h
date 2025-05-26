#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <cmath>

// Virtual class used for all entities in the game
class Entity
{
protected:
    sf::CircleShape *body;    // Shape representing the entity
    float speed;              // Speed of the entity
    sf::Vector2f destination; // Target position for movement
    bool isPlayer;            // True if the entity is a player or a projectile spawned by the player
    bool isDestroyed;         // True if the entity needs to be destroyed

public:
    // Default constructor
    Entity();

    // Parameterized constructor
    // Inputs: radius, position, color, speed, destination, isPlayer
    Entity(int r, sf::Vector2f position, sf::Color color, float speed,
           sf::Vector2f destination, bool isPlayer);

    // Copy constructor
    // Inputs: entity - another Entity object to copy from
    Entity(const Entity &entity);

    // Pure virtual function to get the type of the entity
    // Output: string representing the type of the entity (e.g., "player", "enemy", "projectile")
    // This function must be implemented by derived classes
    virtual std::string getType() = 0;

    // Moves the entity towards its destination by speed units
    virtual void move();

    // Checks if the entity collides with another entity of a different isPlayer
    // Inputs: pointer to another Entity object
    // Output: true if there is a collision, false otherwise
    bool checkCollision(Entity *entity);

    // Draws the entity to the given render window
    // Inputs: pointer to the SFML render window
    void draw(sf::RenderWindow *win);

    // Returns the position of the entity
    // Output: current position of the entity as a sf::Vector2f
    sf::Vector2f getPosition();

    // Returns the destination of the entity
    // Output: target position of the entity as a sf::Vector2f
    sf::Vector2f getDestination();

    // Returns the speed of the entity
    // Output: speed of the entity as a float
    float getSpeed();

    // Returns whether the entity needs to be destroyed
    // Output: true if the entity is marked for destruction, false otherwise
    bool getIsDestroyed();

    // Destructor
    ~Entity();
};

#endif
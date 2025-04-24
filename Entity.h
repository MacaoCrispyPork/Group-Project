#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Entity
{
protected:
    sf::CircleShape *body;
    float speed;
    sf::Vector2f destination;
    // Not implemented in collision check yet
    bool isPlayer;

public:
    Entity();
    Entity(int r, int x, int y, sf::Color color, int speed,
           float destinationX, float destinationY, bool isPlayer);

    virtual std::string getType();

    void move(sf::Vector2f finish);

    bool checkCollision(Entity *entity);

    void draw(sf::RenderWindow *win);

    sf::Vector2f getPosition();

    sf::Vector2f getDestination();

    float getSpeed();

    ~Entity();
};

#endif
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
    Entity(int r, int x, int y, sf::Color color, int speed, float destinationX, float destinationY, bool isPlayer): speed(speed), isPlayer(isPlayer)
    {
        body = new sf::CircleShape();
        body->setRadius(r);
        body->setPosition(x, y);
        body->setFillColor(color);
        // Might not be needed
        body->setOrigin(r / 2, r / 2);
        destination = sf::Vector2f(destinationX, destinationY);
    }

    Entity() : Entity(0, 0, 0, sf::Color::Cyan, 0, 0, 0, NULL) {}

    virtual std::string getType()
    {
        return "Entity";
    }

    void move(sf::Vector2f finish)
    {
        // Creates a vector movement in the direction of destination
        sf::Vector2f movement = finish - body->getPosition();
        // Checks if the movemement is not directly along a cardinal axis
        if (movement.x != 0.f || movement.y != 0.f)
        {
            // Finds the length of the vector
            float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
            // Divide by length to normalise the length of the vector to 1
            movement /= length;
            // Multiply by speed
            // Non linear speed would be a cool feature like it accelerates and deccelerates
            movement *= speed;
        }
        // Moves the entity only if it is further away from its destination then half the speed. This value can be tweaked
        if (std::sqrt((body->getPosition().x - finish.x) * (body->getPosition().x - finish.x) + (body->getPosition().y - finish.y) * (body->getPosition().y - finish.y)) > speed / 2)
        {
            body->move(movement);
        }
    }

    bool checkCollision(Entity *entity)
    {
        float distance = std::sqrt((body->getPosition().x - entity->body->getPosition().x) * (body->getPosition().x - entity->body->getPosition().x) + (body->getPosition().y - entity->body->getPosition().y) * (body->getPosition().y - entity->body->getPosition().y));
        return (distance < body->getRadius() + entity->body->getRadius());
    }

    void draw(sf::RenderWindow *win)
    {
        win->draw(*body);
    }

    sf::Vector2f getPosition()
    {
        return body->getPosition();
    }

    sf::Vector2f getDestination()
    {
        return destination;
    }

    int getSpeed()
    {
        return speed;
    }

    ~Entity() {delete body;}
};

#endif
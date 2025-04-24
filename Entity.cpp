#include <SFML/Graphics.hpp>
#include <cmath>
#include "Entity.h"

Entity::Entity() : Entity(0, sf::Vector2(0.f, 0.f), sf::Color::Cyan, 0, sf::Vector2(0.f, 0.f), NULL) {}

Entity::Entity(int r, sf::Vector2f position, sf::Color color, int speed,
    sf::Vector2f destination, bool isPlayer)
    : speed(speed), isPlayer(isPlayer)
{
    body = new sf::CircleShape();
    body->setRadius(r);
    body->setPosition(position);
    body->setFillColor(color);
    // Might not be needed
    body->setOrigin(r / 2, r / 2);
}

std::string Entity::getType()
{
    return "Entity";
}

void Entity::move(sf::Vector2f finish)
{
    // Creates a vector movement in the direction of destination
    sf::Vector2f movement = finish - body->getPosition();
    // Finds the length of the vector
    float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);
    // Divide by length to normalise the length of the vector to 1
    movement /= length;
    // Multiply by speed
    movement *= speed;
    // Moves the entity only if it is further away from its destination then half the speed. This value can be tweaked
    if (std::sqrt((body->getPosition().x - finish.x) * (body->getPosition().x - finish.x) + (body->getPosition().y - finish.y) * (body->getPosition().y - finish.y)) > speed / 2)
    {
        body->move(movement);
    }
}

bool Entity::checkCollision(Entity *entity)
{
    float distance = std::sqrt((body->getPosition().x - entity->body->getPosition().x) * (body->getPosition().x - entity->body->getPosition().x) + (body->getPosition().y - entity->body->getPosition().y) * (body->getPosition().y - entity->body->getPosition().y));
    return (distance < body->getRadius() + entity->body->getRadius());
}

void Entity::draw(sf::RenderWindow *win)
{
    win->draw(*body);
}

sf::Vector2f Entity::getPosition()
{
    return body->getPosition();
}

sf::Vector2f Entity::getDestination()
{
    return destination;
}

float Entity::getSpeed()
{
    return speed;
}

Entity::~Entity() { delete body; }
#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Entity 
{
protected:
    sf::CircleShape* body;
    float speed;
    sf::Vector2f destination;
    bool isPlayer;
public:
    Entity(int r, int x, int y) {
        body = new sf::CircleShape();
        body->setRadius(r);
        body->setPosition(x,y);
        body->setFillColor(sf::Color::Cyan);
        body->setOrigin(r/2,r/2);
        speed = 0;
        destination = sf::Vector2f(0.f,0.f);
    }
    Entity() {
        body = new sf::CircleShape();
        body->setRadius(0);
        body->setPosition(0,0);
        body->setFillColor(sf::Color::Cyan);
        speed = 0;
        destination = sf::Vector2f(0.f,0.f);
    }
    virtual std::string getType() {
        return "Entity";
    }
    void move(sf::Vector2f finish) {
        sf::Vector2f movement = finish - body->getPosition();
        if (movement.x != 0.f || movement.y != 0.f) {
            float length = std::sqrt(movement.x*movement.x + movement.y*movement.y);
            movement /= length;
            movement *= speed; 
        }
        if (std::sqrt((body->getPosition().x-finish.x)*(body->getPosition().x-finish.x)+(body->getPosition().y-finish.y)*(body->getPosition().y-finish.y)) > speed/2) {
            body->move(movement);
        }
    }
    bool checkCollision(Entity* entity) {
        float distance = std::sqrt((body->getPosition().x-entity->body->getPosition().x)*(body->getPosition().x-entity->body->getPosition().x)+(body->getPosition().y-entity->body->getPosition().y)*(body->getPosition().y-entity->body->getPosition().y));
        return (distance < body->getRadius() + entity->body->getRadius());
    }
    void draw(sf::RenderWindow* win) {
        win->draw(*body);
    }
    sf::Vector2f getPosition() {
        return sf::Vector2f(body->getPosition().x,body->getPosition().y);
    }
    sf::Vector2f getDestination() {
        return sf::Vector2f(destination.x,destination.y);
    }
    int getSpeed() {
        return speed;
    }

};

#endif
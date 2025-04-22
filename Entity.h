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
    //Not implemented in collision check yet
    bool isPlayer;
public:
    Entity(int r, int x, int y) {
        body = new sf::CircleShape();
        body->setRadius(r);
        body->setPosition(x,y);
        body->setFillColor(sf::Color::Cyan);
        //More testing required whether the origin should actually be set
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
    //Not the best way to implemenet this. Is there some function like get_type() of variable we could use instead?
    virtual std::string getType() {
        return "Entity";
    }
    void move(sf::Vector2f finish) {
        //Creates a vector movement in the direction of destination
        sf::Vector2f movement = finish - body->getPosition();
        //Checks if the movemement is not directly along a cardinal axis
        if (movement.x != 0.f || movement.y != 0.f) {
            //Finds the length of the vector
            float length = std::sqrt(movement.x*movement.x + movement.y*movement.y);
            //Divide by length to normalise the length of the vector to 1
            movement /= length;
            //Multiply by speed
            //Non linear speed would be a cool feature like it accelerates and deccelerates
            movement *= speed; 
        }
        //Moves the entity only if it is further away from its destination then half the speed. This value can be tweaked
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
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
    bool isPlayer;
    bool isDestroyed;

public:
    Entity();
    Entity(int r, sf::Vector2f position, sf::Color color, float speed,
        sf::Vector2f destination, bool isPlayer);
    Entity(const Entity &entity);

    virtual std::string getType() = 0;

    virtual void move();

    bool checkCollision(Entity *entity);

    void draw(sf::RenderWindow *win);

    sf::Vector2f getPosition();

    sf::Vector2f getDestination();

    float getSpeed();

    bool getIsDestroyed();

    ~Entity();
};

#endif
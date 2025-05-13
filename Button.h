#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

// this was made with the help of chatgpt

class Button
{
public:
    sf::RectangleShape shape;
    sf::Text text;

    Button(sf::Vector2f size, sf::Vector2f position, const std::string &label, sf::Font &font);

    bool isClicked(sf::Vector2i mousePos);

    void draw(sf::RenderWindow &window);
};

#endif
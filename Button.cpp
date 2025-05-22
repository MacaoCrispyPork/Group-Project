#include "Button.h"

// this was made with the help of chatgpt

Button::Button(sf::Vector2f size, sf::Vector2f position, const std::string &label, sf::Font &font)
{
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Black);

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(position.x + 10, position.y + 10); // Offset for padding
}

bool Button::isClicked(sf::Vector2i mousePos)
{
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(text);
}
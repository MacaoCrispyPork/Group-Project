#include "Button.h"

sf::SoundBuffer Button::sharedBuffer;
bool Button::bufferLoaded = false;

Button::Button()
{
    shape.setSize(sf::Vector2f(0,0));
    shape.setPosition(sf::Vector2f(0,0));
    shape.setFillColor(sf::Color::Black);

    // Check if the buffer has been loaded and if not it loads the buffer
    if (!bufferLoaded)
    {
        sharedBuffer.loadFromFile("buttonclicked.wav");
    }
    // Sets the sound to play from the buffer
    sound.setBuffer(sharedBuffer);
}


Button::Button(sf::Vector2f size, sf::Vector2f position, const std::string &label, sf::Font &font, sf::Color color)
{
    shape.setSize(size);
    shape.setPosition(position);
    shape.setFillColor(sf::Color::Black);

    text.setFont(font);
    text.setString(label);
    text.setCharacterSize(24);
    text.setFillColor(color);
    text.setPosition(position.x + 10, position.y + 10); // Offset for padding

    if (!bufferLoaded)
    {
        sharedBuffer.loadFromFile("buttonclicked.wav");
    }
    sound.setBuffer(sharedBuffer);
}

bool Button::isClicked(sf::Vector2i mousePos)
{
    if (shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
    {
        sound.play();
    } 
    return shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::draw(sf::RenderWindow &window)
{
    window.draw(shape);
    window.draw(text);
}

void Button::setText(std::string text)
{
    this->text.setString(text);
}

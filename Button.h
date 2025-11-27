#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


// Class used for creating menu buttons
class Button
{
private:
    sf::RectangleShape shape; // Shape representing the button's body
    sf::Text text;            // Text displayed on the button
    static sf::SoundBuffer sharedBuffer; // Sound buffer for playing sounds. Static variable to cut down on memory usage
    static bool bufferLoaded; // Check for whether the buffer has already been loaded for all button instances
    sf::Sound sound; // Object for playing sounds


public:
    // Constructor

    Button();

    // Inputs: size, position, label, font
    Button(sf::Vector2f size, sf::Vector2f position, const std::string &label, sf::Font &font, sf::Color color);

    // Checks whether the button is clicked based on mouse position
    // Input: mousePos - position of the mouse in window coordinates
    // Output: true if the mouse position intersects with the button, false otherwise
    bool isClicked(sf::Vector2i mousePos);

    // Renders the button to the given render window
    // Input: window - the SFML window where the button will be drawn
    void draw(sf::RenderWindow &window);

    // Allows for the updating of the text displayed by the button
    // Input: text - the string to be displayed by the button
    void setText(std::string text);
};

#endif // BUTTON_H

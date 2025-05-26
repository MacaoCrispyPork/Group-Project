#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

// Class used for creating menu buttons
class Button
{
private:
    sf::RectangleShape shape; // Shape representing the button's body
    sf::Text text;            // Text displayed on the button

public:
    // Constructor
    // Inputs: size, position, label, font
    Button(sf::Vector2f size, sf::Vector2f position, const std::string &label, sf::Font &font);

    // Checks whether the button is clicked based on mouse position
    // Input: mousePos - position of the mouse in window coordinates
    // Output: true if the mouse position intersects with the button, false otherwise
    bool isClicked(sf::Vector2i mousePos);

    // Renders the button to the given render window
    // Input: window - the SFML window where the button will be drawn
    void draw(sf::RenderWindow &window);
};

#endif // BUTTON_H

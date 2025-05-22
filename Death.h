#ifndef DEATH_H
#define DEATH_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"

class Death
{
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text title;
    sf::Text highScore;
    sf::Text Score;
    Button Continue;
public:
    Death(sf::RenderWindow& window, sf::Font font);
    void handleInput(sf::Event event, gameState state);
    void draw();
};

#endif
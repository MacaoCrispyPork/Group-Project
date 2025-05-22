#ifndef MAINMENU_H
#define MAINMENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"

class mainMenu
{
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text title;
    sf::Text HTP;
    Button playBtn;
    Button exitBtn;
public:
    mainMenu(sf::RenderWindow& window, sf::Font font);
    void handleInput(sf::Event event, gameState state);
    void draw();
};

#endif 
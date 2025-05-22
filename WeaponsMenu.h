#ifndef WEAPONSMENU_H
#define WEAPONSMENU_H

#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"

class weaponsMenu
{
private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text title;
    sf::Text desciptionB;
    sf::Text desciptionS;
    Button bowBtn;
    Button swordBtn;
public:
    weaponsMenu(sf::RenderWindow& window, sf::Font font);
    void handleInput(sf::Event event, gameState state);
    void draw();
};

#endif 
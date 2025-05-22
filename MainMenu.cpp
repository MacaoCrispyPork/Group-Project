#include "MainMenu.h"

mainMenu::mainMenu(sf::RenderWindow &window, sf::Font font) : window(window),
                                                              font(font),
                                                              playBtn({200, 50}, {300, 300}, "Play!", font),
                                                              exitBtn({200, 50}, {300, 400}, "Exit :(", font)
{
    title.setFont(font);
    title.setString("Slayer");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);

    // Setting text position to center top of the screen
    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top);
    title.setPosition(window.getSize().x / 2.0f, 30.f);

    HTP.setFont(font);
    HTP.setString("How to Play:\nRight Click = Move\nLeft Click = Attack");
    HTP.setCharacterSize(48);
    HTP.setFillColor(sf::Color::White);
    HTP.setPosition(1000, 300);
}

void mainMenu::handleInput(sf::Event event, gameState state)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i mouse(event.mouseButton.x, event.mouseButton.y);

        if (state == gameState::Main_Menu)
        {
            if (playBtn.isClicked(mouse))
            {
                state = gameState::Weapons_Menu;
            }
            else if (exitBtn.isClicked(mouse))
            {
                window.close();
            }
        }
    }
}

void mainMenu::draw()
{
    window.draw(title);
    window.draw(HTP);
    playBtn.draw(window);
    exitBtn.draw(window);
}
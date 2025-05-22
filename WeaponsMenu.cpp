#include "WeaponsMenu.h"

weaponsMenu::weaponsMenu(sf::RenderWindow &window, sf::Font font) : window(window),
                                                                    font(font),
                                                                    bowBtn({200, 50}, {300, 300}, "Play!", font),
                                                                    swordBtn({200, 50}, {900, 300}, "Exit :(", font)
{
    title.setFont(font);
    title.setString("Choose Your Weapon!");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);

    // Setting text position to center top of the screen
    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top);
    title.setPosition(window.getSize().x / 2.0f, 30.f);

    desciptionB.setFont(font);
    desciptionB.setString("Ranged Weapon aim with cursor");
    desciptionB.setCharacterSize(48);
    desciptionB.setFillColor(sf::Color::White);
    desciptionB.setPosition(300, 400);

    desciptionS.setFont(font);
    desciptionS.setString("Melee Weapon short ranged omnidirectional attack");
    desciptionS.setCharacterSize(48);
    desciptionS.setFillColor(sf::Color::White);
    desciptionS.setPosition(300, 400);
}

void weaponsMenu::handleInput(sf::Event event, gameState state)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i mouse(event.mouseButton.x, event.mouseButton.y);

        if (state == gameState::Main_Menu)
        {
            if (bowBtn.isClicked(mouse))
            {
                state = gameState::Game;
            }
            else if (swordBtn.isClicked(mouse))
            {
                state = gameState::Game;
            }
        }
    }
}

void weaponsMenu::draw()
{
    window.draw(title);
    window.draw(desciptionB);
    window.draw(desciptionS);
    bowBtn.draw(window);
    swordBtn.draw(window);
}
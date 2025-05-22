#include "Death.h"

Death::Death(sf::RenderWindow &window, sf::Font font) : window(window),
                                                        font(font),
                                                        Continue({200, 50}, {300, 300}, "Play!", font)
{
    title.setFont(font);
    title.setString("YOU DIED");
    title.setCharacterSize(48);
    title.setFillColor(sf::Color::White);

    // Setting text position to center top of the screen
    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top);
    title.setPosition(window.getSize().x / 2.0f, 30.f);

    highScore.setFont(font);
    highScore.setString("HIGHSCORE:");
    highScore.setCharacterSize(48);
    highScore.setFillColor(sf::Color::White);
    highScore.setPosition(1000, 300);

    Score.setFont(font);
    Score.setString("SCORE:");
    Score.setCharacterSize(48);
    Score.setFillColor(sf::Color::White);
    Score.setPosition(500, 300);
}

void Death::handleInput(sf::Event event, gameState state)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i mouse(event.mouseButton.x, event.mouseButton.y);

        if (state == gameState::Death)
        {
            if (Continue.isClicked(mouse))
            {
                state = gameState::MainMenu;
            }
        }
    }
}

void Death::draw()
{
    window.draw(title);
    window.draw(highScore);
    window.draw(Score);
    Continue.draw(window);
}
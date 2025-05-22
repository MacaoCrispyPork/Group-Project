#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "GameState.h"

// export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
int main()
{
    // srand(time(0)); 

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Slayer Menu");

    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF"))
    {
        return -1;
    }

    gameState state = gameState::MainMenu;

    // Buttons
    Button playBtn({200, 50}, {300, 200}, "Play!", font);
    Button quitBtn({200, 50}, {300, 300}, "Exit :(", font);
    Button wBow({200, 50}, {300, 200}, "Bow", font);
    Button wSword({200, 50}, {300, 300}, "Sword", font);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mouse(event.mouseButton.x, event.mouseButton.y);

                if (state == gameState::MainMenu)
                {
                    if (playBtn.isClicked(mouse))
                    {
                        state = gameState::WeaponsMenu;
                    }
                
                    else if (quitBtn.isClicked(mouse))
                    {
                        window.close();
                    }
                }

                else if (state == gameState::WeaponsMenu)
                {
                    if (wBow.isClicked(mouse) || wSword.isClicked(mouse))
                    {
                        // You can use a flag here to distinguish Option 1 vs 2
                        window.close(); // Close menu window
                        Game g(1920, 1080, "Slayer");
                        g.run();  // Start the game
                        return 0; // Exit after game finishes
                    }
                }
            }
        }

        window.clear();

        if (state == gameState::MainMenu)
        {
            playBtn.draw(window);
            quitBtn.draw(window);
        }
        else if (state == gameState::WeaponsMenu)
        {
            wBow.draw(window);
            wSword.draw(window);
        }

        window.display();
    }

    return 0;
}
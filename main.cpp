#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Button.h"
#include "GameState.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Slayer Menu");

    // Loading the custom font.
    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF"))
    {
        return -1;
    }

    // Initialising the game's state as the main menu.
    gameState state = gameState::MainMenu;

    // Initialising buttons for the main menu.
    Button Title({0, 0}, {540, 0}, "Slayer", font);
    Button playBtn({200, 50}, {360, 200}, "Play!", font);
    Button quitBtn({200, 50}, {360, 300}, "Exit :(", font);

    // Initialising buttons for the weapons menu.
    Button Weapon({0, 0}, {540, 0}, "Choose Your Weapon", font);
    Button wBow({200, 50}, {360, 200}, "Bow", font);
    Button wSword({200, 50}, {720, 200}, "Sword", font);

    // Initialising buttons for the death menu.
    Button Continue({200, 50}, {540, 300}, "Continue", font);

    // Initialising unpressable buttons to use as textboxes.
    Button mainDescription({0, 0}, {720, 200}, "How to Play:\nRight Click = Move\nLeft Click = Attack", font);
    Button BowDescription({0, 0}, {360, 300}, "Ranged Weapon \naim with cursor", font);
    Button SwordDescription({0, 0}, {720, 300}, "Melee Weapon \nshort ranged \nomnidirectional attack", font);
    Button Died({0, 0}, {540, 200}, "YOU DIED", font);
    
    // Starting the game making sure that the game window is open on the users screen.
    while (window.isOpen())
    {
        // Looking for user input.
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Closes window if the user chooses to quit.
            if (event.type == sf::Event::Closed)
                window.close();
            
            // Handling mouse inputs.
            if (event.type == sf::Event::MouseButtonPressed)
            {
                
                sf::Vector2i mouse(event.mouseButton.x, event.mouseButton.y);

                // Handling input for the main manu
                if (state == gameState::MainMenu)
                {
                    if (playBtn.isClicked(mouse))
                    {
                        state = gameState::WeaponsMenu; // Transitioning to the weapons menu 
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
                        state = gameState::Game;
                        Game g(1920, 1080, "Slayer");
                        bool playerDied = g.run(); // Start the game and wait for it to end
                        if (playerDied)
                            state = gameState::Death;
                        else
                            state = gameState::MainMenu; // just in case
                    }
                }

                else if (state == gameState::Death)
                {
                    if (Continue.isClicked(mouse))
                    {
                        state = gameState::MainMenu;
                    }
                }
            }
        }

        window.clear();

        if (state == gameState::MainMenu)
        {
            Title.draw(window);
            playBtn.draw(window);
            quitBtn.draw(window);
            mainDescription.draw(window);
        }
        else if (state == gameState::WeaponsMenu)
        {
            Weapon.draw(window);
            wBow.draw(window);
            wSword.draw(window);
            BowDescription.draw(window);
            SwordDescription.draw(window);
        }
        else if (state == gameState::Death)
        {
            Died.draw(window);
            Continue.draw(window);
        }
        window.display();
    }
    return 0;
}
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include "Game.h"
#include "Button.h"
#include "GameState.h"
#include <SFML/Audio.hpp>

#include "Weapon.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Slayer Menu");

    // Loading the custom font.
    sf::Font font;
    if (!font.loadFromFile("ARIAL.TTF"))
    {
        return -1;
    }
    int score = 0;



    // Initialising the game's state as the main menu.
    gameState state = gameState::MainMenu;

    // Initialising buttons for the main menu.
    Button playBtn({200, 50}, {360, 200}, "Play!", font, sf::Color::Green);
    Button quitBtn({200, 50}, {360, 300}, "Exit :(", font, sf::Color::Red);

    // Initialising buttons for the weapons menu.
    Button wBow({200, 50}, {360, 200}, "Bow", font, sf::Color::Cyan);
    Button wSword({200, 50}, {720, 200}, "Sword", font, sf::Color::Green);

    // Initialising buttons for the death menu.
    Button Score({0, 0}, {540, 300}, "Your Score: " + std::to_string(score), font, sf::Color::White);
    Button Continue({200, 50}, {540, 400}, "Continue", font, sf::Color::White);

    // Initialising unpressable buttons to use as textboxes.
    Button Title({0, 0}, {540, 0}, "Slayer", font, sf::Color::White);
    Button MainDescription({0, 0}, {720, 200}, "How to Play:\nRight Click = Move\nSpace = Attack", font, sf::Color::White);
    Button ChooseWeapon({0, 0}, {540, 0}, "Choose Your Weapon", font, sf::Color::Magenta);
    Button BowDescription({0, 0}, {360, 300}, "Ranged Weapon \naim with cursor", font, sf::Color::Cyan);
    Button SwordDescription({0, 0}, {720, 300}, "Melee Weapon \nshort ranged \nomnidirectional attack", font, sf::Color::Green);
    Button Died({0, 0}, {540, 200}, "YOU DIED :(", font, sf::Color::Red);
    Button HighScore({0, 0}, {540, 100}, "High Score: ", font, sf::Color::White);

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
                        state = gameState::WeaponsMenu; // Go to the weapons menu
                    }
                    else if (quitBtn.isClicked(mouse))
                    {
                        window.close(); // Close the game.
                    }
                    
                }

                // Handling input ofr weapons menu
                else if (state == gameState::WeaponsMenu)
                {
                    if (wBow.isClicked(mouse) || wSword.isClicked(mouse))
                    {
                        Weapon weapon;
                        if (wSword.isClicked(mouse))
                        {
                            weapon = Weapon(2, .08, 50, .2, 5); // Melee weapon
                        }
                        if (wBow.isClicked(mouse))
                        {
                            weapon = Weapon(1, .15, 4, 3, 600); // Ranged weapon
                        }
                        state = gameState::Game; // Transition to the game menu
                        Game g(1920, 1080, "Slayer", weapon);
                        bool playerDied = g.run();
                        score = g.getScore();
                        if (playerDied)
                        state = gameState::Death;
                        std::ifstream infile("highscore.txt");
                        int highscore = 0;
                        if (infile.is_open())
                        {
                            infile >> highscore;
                            infile.close();
                        }
                        if (score > highscore)
                        {
                            std::ofstream outfile("highscore.txt");
                            if (outfile.is_open())
                            {
                                outfile << score;
                                outfile.close();
                            }
                        }
                    }
                }

                // Handling input for weapons menu
                else if (state == gameState::Death)
                {
                    if (Continue.isClicked(mouse))
                    {
                        state = gameState::MainMenu; // Return to main menu
                    }
                }
            }
        }

        window.clear();

        // Drawing the buttons and text.
        if (state == gameState::MainMenu)
        {
            Title.draw(window);
            std::ifstream hsfile("highscore.txt");
            std::string updatedScore;
            std::getline(hsfile, updatedScore);
            hsfile.close();
            if (updatedScore.empty()) updatedScore = "0";

            HighScore.setText("High Score: " + updatedScore);            HighScore.draw(window);
            playBtn.draw(window);
            quitBtn.draw(window);
            MainDescription.draw(window);
        }
        else if (state == gameState::WeaponsMenu)
        {
            ChooseWeapon.draw(window);
            wBow.draw(window);
            wSword.draw(window);
            BowDescription.draw(window);
            SwordDescription.draw(window);
        }
        else if (state == gameState::Death)
        {
            Died.draw(window);
            Score.setText("Score: " + std::to_string(score));
            Score.draw(window);
            Continue.draw(window);
        }
        window.display();
    }
    return 0;
}
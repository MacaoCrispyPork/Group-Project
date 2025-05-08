#include "Game.h"

Game::Game(int sizeX, int sizeY, std::string title)
{
    win = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title);
    // Size of these arrays is just a random number probably best to replace with a variable
    all_characters = new Character *[10]{nullptr};
    all_projectiles = new Projectile *[10]{nullptr};
    Weapon *weapon = new Bow(10, 1, 2, 1, 300);
    player = new Player(10, sf::Vector2f(50, 50), 3, 1, weapon);
    all_characters[0] = player;
    // Creating Zombies with randomised position
    for (int i = 1; i < 10; i++)
    {
        // all_characters[i] = new Zombie(5, sf::Vector2f(rand() % sizeX + 10, rand() % sizeY + 10), 1, 10, weapon, .1);
    }
    // Filling the projectile array with generic projectiles
    for (int i = 0; i < 10; i++)
    {
        //all_projectiles[i] = new Projectile();
    }
    projectileCount = 0;
}

void Game::run()
{
    while (win->isOpen())
    {
        sf::Event event;
        bool a = 1;

        while (win->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win->close();
                // The gained focus and lost focus is just some code I added so the game will freeze if it is not the main window. But I broke the code at some point so idk.
            }
            else if (event.type == sf::Event::GainedFocus)
            {
                std::cout << "Gained" << std::endl;
                a = 1;
            }
            else if (event.type == sf::Event::LostFocus)
            {
                std::cout << "Lost" << std::endl;
                a = 0;
            }
            // Checking for spacebar being pressed
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    std::optional<Projectile> attack = player->attack(sf::Vector2f(sf::Mouse::getPosition(*win)));
                    if (attack)
                    {
                        if (projectileCount >= 10) projectileCount = 0;
                        if (all_projectiles[projectileCount]) delete all_projectiles[projectileCount];
                        all_projectiles[projectileCount] = new Projectile(attack.value());
                        projectileCount++;
                    }
                }
            }
        }

        if (a)
        {

            player->setPosition(win);
            for (int i = 0; i < 10; i++)
            {
                if (all_characters[i] != nullptr) {
                    if (all_characters[i]->getType() == "Player")
                    {
                        all_characters[i]->move(player->getDestination());
                    }
                    else if (all_characters[i]->getType() == "Zombie")
                    {
                        all_characters[i]->move(player->getPosition());
                    }
                }
            }
            // Basic movement code
            // To-do: recode movement function to use destination
            for (int i = 0; i < 10; i++)
            {
                if (all_projectiles[i] != nullptr) all_projectiles[i]->move(all_projectiles[i]->getDestination());
            }
            // Damage actually means nothing right now but I think this code works
            for (int i = 0; i < 10; i++)
            {
                if (all_characters[i] != nullptr) {
                    for (int j = 0; j < 10; j++)
                    {
                        if (all_characters[i]->checkCollision(all_projectiles[j]))
                        {
                            std::cout << clock() / CLOCKS_PER_SEC << " : " << all_characters[i]->getType() << " " << i << " collided with " << all_projectiles[j]->getType() << " " << j << std::endl;
                            all_characters[i]->takeDamage(all_projectiles[j]->getDamage());
                        };
                    }
                    if (all_characters[i]->getIsDestroyed()) {
                        delete all_characters[i];
                        all_characters[i] = nullptr;
                    }
                }
            }
            // Here is where we will delete projectile after it hits something
            for (int i = 0; i < 10; i++)
            {
                if (all_projectiles[i] != nullptr) {
                    for (int j = 0; j < 10; j++)
                    {
                        if (all_projectiles[i]->checkCollision(all_characters[j]))
                        {
                            std::cout << float(clock() / CLOCKS_PER_SEC) << " : " << all_projectiles[i]->getType() << " " << i << " collided with " << all_characters[j]->getType() << " " << j << std::endl;
                        };
                    }
                    if (all_projectiles[i]->getIsDestroyed()) {
                        delete all_projectiles[i];
                        all_projectiles[i] = nullptr;
                    }
                }
            }

            win->clear();
            // Cycling through array to draw them

            for (int i = 0; i < 10; i++)
            {
                if (all_characters[i] != nullptr) all_characters[i]->draw(win);
            }

            for (int i = 0; i < 10; i++)
            {
                if (all_projectiles[i] != nullptr) all_projectiles[i]->draw(win);
            }
            win->display();
        }
    }
}

Game::~Game()
{
    for (int i = 0; i < 10; i++)
    {
        delete all_projectiles[i];
    }
    delete[] all_projectiles;

    for (int i = 0; i < 10; i++)
    {
        delete all_characters[i];
    }
    delete[] all_characters;
}
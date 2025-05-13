#include "Game.h"

Game::Game(int sizeX, int sizeY, std::string title)
{
    win = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title);
    // Size of these arrays is just a random number probably best to replace with a variable
    all_characters = new Character *[10]{nullptr};
    all_projectiles = new Projectile *[10]{nullptr};
    Weapon *weapon = new Weapon(1, 0.2, 2, 1, 300);
    player = new Player(10, sf::Vector2f(50, 50), 3, 1, weapon);
    all_characters[0] = player;
    // Creating Zombies with randomised position
    for (int i = 1; i < 10; i++)
    {
        all_characters[i] = new Zombie(10, sf::Vector2f(rand() % sizeX + 10, rand() % sizeY + 10), 2, 3, new Weapon(*weapon), .1);
    }
    // Filling the projectile array with generic projectiles
    for (int i = 0; i < 10; i++)
    {
        // all_projectiles[i] = new Projectile();
    }
    projectileCount = 0;
}

void Game::run()
{
    while (win->isOpen())
    {
        bool isFocused = handleEvents();

        if (isFocused)
        {
            updateGameState();
            render();
        }
    }
}

bool Game::handleEvents()
{
    sf::Event event;
    bool isFocused = true;

    while (win->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            win->close();
            break;
        case sf::Event::GainedFocus:
            std::cout << "Gained" << std::endl;
            isFocused = true;
            break;
        case sf::Event::LostFocus:
            std::cout << "Lost" << std::endl;
            isFocused = false;
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space)
            {
                handlePlayerAttack();
            }
            break;
        default:
            break;
        }
    }

    return isFocused;
}

void Game::handlePlayerAttack()
{
    std::optional<Projectile> attack = player->attack(sf::Vector2f(sf::Mouse::getPosition(*win)));
    if (attack)
    {
        if (projectileCount >= 10)
            projectileCount = 0;
        if (all_projectiles[projectileCount])
            delete all_projectiles[projectileCount];
        all_projectiles[projectileCount] = new Projectile(attack.value());
        projectileCount++;
    }
}

void Game::updateGameState()
{
    player->setPosition(win);
    moveCharacters();
    moveProjectiles();
    handleCharacterCollisions();
    handleProjectileCollisions();
    deleteDestroyedEntities();
}

void Game::moveCharacters()
{
    for (int i = 0; i < 10; i++)
    {
        if (all_characters[i])
        {
            all_characters[i]->move();
        }
    }
}

void Game::moveProjectiles()
{
    for (int i = 0; i < 10; i++)
    {
        if (all_projectiles[i])
        {
            all_projectiles[i]->move();
        }
    }
}

void Game::handleCharacterCollisions()
{
    for (int i = 0; i < 10; i++)
    {
        if (!all_characters[i])
        {
            continue;
        }

        for (int j = 0; j < 10; j++)
        {
            all_characters[i]->handleCollision(all_projectiles[j]);
        }
    }
}

void Game::handleProjectileCollisions()
{
    for (int i = 0; i < 10; i++)
    {
        if (!all_projectiles[i])
        {
            continue;
        }

        for (int j = 0; j < 10; j++)
        {
            all_projectiles[i]->handleCollision(all_characters[j]);
            all_projectiles[i]->handleCollision(all_projectiles[j]);
        }
    }
}

void Game::deleteDestroyedEntities()
{
    for (int i = 0; i<10; i++) {
        if (all_characters[i] && all_characters[i]->getIsDestroyed())
        {
            delete all_characters[i];
            all_characters[i] = nullptr;
        }
        if (all_projectiles[i] && all_projectiles[i]->getIsDestroyed())
        {
            delete all_projectiles[i];
            all_projectiles[i] = nullptr;
        }
    }
}

void Game::render()
{
    win->clear();
    for (int i = 0; i < 10; i++)
    {
        if (all_characters[i])
            all_characters[i]->draw(win);
    }
    for (int i = 0; i < 10; i++)
    {
        if (all_projectiles[i])
            all_projectiles[i]->draw(win);
    }
    win->display();
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
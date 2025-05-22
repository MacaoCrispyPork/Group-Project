#include "Game.h"

Game::Game(int sizeX, int sizeY, std::string title)
{
    win = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title);
    Weapon *weapon = new Weapon(1, 0.2, 5, 2, 500);
    player = new Player(10, sf::Vector2f(sizeX/2, sizeY/2), 3, 5, weapon);
    score = 0;
    wave = 1;
    spawnWaveEnemies(wave, sizeX, sizeY);
}

void Game::spawnWaveEnemies(int wave, int sizeX, int sizeY)
{
    for (int i = 0; i < wave; i++)
    {
        int x, y;
        if (rand() % 2 == 0)
            x = rand() % (sizeX / 3);
        else
            x = sizeX - (rand() % (sizeX / 3)) - 1;
        if (rand() % 2 == 0)
            y = rand() % (sizeY / 3);
        else
            y = sizeY - (rand() % (sizeY / 3)) - 1;
        if (rand() % 2 == 0) {
            all_enemies.push_back(new Skeleton(10, sf::Vector2f(x, y), 3, new Weapon(1, 0.5, 5, 2, 800), 1, 0));
        }
        else {
            all_enemies.push_back(new Zombie(10, sf::Vector2f(x, y), 1, 3, new Weapon(2, 0.3, 35, 0.75, 25), 1, 0.3));
        }
    }
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

        if (player->getIsDestroyed())
        {
            std::cout << "Game Over!" << std::endl;
            std::cout << "Score: " << score << std::endl;
            win->close();
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
            isFocused = true;
            break;
        case sf::Event::LostFocus:
            isFocused = false;
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Space)
            {
                handlePlayerAttack();
            }
            break;
        case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                player->setDestination(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*win)));
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
        all_projectiles.push_back(new Projectile(attack.value()));
    }
}

void Game::updateGameState()
{
    moveEntities();
    updateAI();
    handleCollisions();
    deleteDestroyedEntities();
        if (all_enemies.empty())
    {
        wave++;
        spawnWaveEnemies(wave, win->getSize().x, win->getSize().y);
    }
}

void Game::moveEntities()
{
    player->move();
    for (Enemy *i : all_enemies)
    {
        i->move();
    }
    for (Projectile *i : all_projectiles)
    {
        i->move();
    }
}

void Game::handleCollisions()
{
    for (Projectile *i : all_projectiles)
    {
        player->handleCollision(i);
        i->handleCollision(player);
        for (Enemy *j : all_enemies)
        {
            j->handleCollision(i);
            i->handleCollision(j);
        }
        for (Projectile *k : all_projectiles)
        {
            i->handleCollision(k);
        }
    }
}

void Game::deleteDestroyedEntities()
{
    for (int i = all_projectiles.size() - 1; i >= 0; i--)
    {
        if (all_projectiles[i]->getIsDestroyed())
        {
            delete all_projectiles[i];
            all_projectiles.erase(all_projectiles.begin() + i);
        }
    }
    for (int i = all_enemies.size() - 1; i >= 0; i--)
    {
        if (all_enemies[i]->getIsDestroyed())
        {
            score += all_enemies[i]->getxp();
            delete all_enemies[i];
            all_enemies.erase(all_enemies.begin() + i);
        }
    }
}

void Game::updateAI()
{
    for (Enemy *i : all_enemies)
    {
        std::optional<Projectile> attack = i->updateAI(player->getPosition());
        if (attack)
        {
            all_projectiles.push_back(new Projectile(attack.value()));
        }
    }
}

void Game::render()
{
    win->clear();
    player->draw(win);
    for (Enemy *i : all_enemies)
    {
        i->draw(win);
    }
    for (Projectile *i : all_projectiles)
    {
        i->draw(win);
    }
    win->display();
}

Game::~Game()
{
    delete win;
    delete player;
    for (int i = 0; i < all_projectiles.size(); i++)
    {
        delete all_projectiles[i];
    }
    all_projectiles.clear();
    for (int i = 0; i < all_enemies.size(); i++)
    {
        delete all_enemies[i];
    }
    all_enemies.clear();
}
#include "Game.h"

Game::Game(int sizeX, int sizeY, std::string title)
{
    win = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title);
    Weapon *weapon = new Weapon(1, 0.2, 2, 1, 300);
    player = new Player(10, sf::Vector2f(50, 50), 3, 1, weapon);
    // Creating Enemies with randomised position
    for (int i = 0; i < 3; i++)
    {
        all_enemies.push_back(new Skeleton(10, sf::Vector2f(rand() % sizeX + 10, rand() % sizeY + 10), 0.5, 3, new Weapon(1, 1, 10, 1, 300), .1, 0.2));
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
        all_projectiles.push_back(new Projectile(attack.value()));
    }
}

void Game::updateGameState()
{
    player->setPosition(win);
    moveEntities();
    updateAI();
    handleCollisions();
    deleteDestroyedEntities();
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
    for (int i = all_projectiles.size()-1; i >= 0; i--)
    {
        if (all_projectiles[i]->getIsDestroyed())
        {
            delete all_projectiles[i];
            all_projectiles.erase(all_projectiles.begin() + i);
        }
    }
    for (int i = all_enemies.size()-1; i >= 0; i--)
    {
        if (all_enemies[i]->getIsDestroyed())
        {
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
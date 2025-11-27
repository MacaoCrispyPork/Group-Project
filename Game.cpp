#include "Game.h"
#include <fstream>

Game::Game(int sizeX, int sizeY, std::string title, Weapon weapon) : scoreCounter(), healthCounter()
{
    win = new sf::RenderWindow(sf::VideoMode(sizeX, sizeY), title);
    win->setFramerateLimit(60);
    win->setVerticalSyncEnabled(true);
    player = new Player(10, sf::Vector2f(sizeX / 2, sizeY / 2), 6, 5, new Weapon(weapon));
    if (!font.loadFromFile("ARIAL.TTF")) {
        std::cerr << "Failed to load font!" << std::endl;
    }    
    score = 0;
    this->scoreCounter = Button({0, 0}, {0, 0}, "Score: 0", font, sf::Color::White);
    this->healthCounter = Button({0, 0}, {0, 60}, "Health: " + std::to_string(player->getHealth()), font, sf::Color::White);

    wave = 1;
    spawnWaveEnemies(wave, sizeX, sizeY);
}

void Game::spawnWaveEnemies(int wave, int sizeX, int sizeY)
{
    for (int i = 0; i < pow(wave, 1.5); i++)
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
        if (rand() % 2 == 0)
        {
            all_enemies.push_back(new Skeleton(10, sf::Vector2f(x, y), 3, new Weapon(1, 0.2+.05*wave, 5, 3, 1000+50*wave), 1, 0));
        }
        else
        {
            all_enemies.push_back(new Zombie(10, sf::Vector2f(x, y), 2+.25*wave, 3, new Weapon(2, 0.5, 40, 1, 25), 1, 0.3));
        }
    }
}

bool Game::run()
{
    clock.restart();
    gameTime.restart();


    while (win->isOpen())
    {
        render();

        if (clock.getElapsedTime().asSeconds() >= (1/60))
        {
            handleEvents();
            updateGameState();

            if (player->getIsDestroyed())
            {
                std::cout << "Game Over!" << std::endl;
                std::cout << "Score: " << score << std::endl;

                // High score logic
                int highscore = 0;
                std::ifstream infile("highscore.txt");
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
                    highscore = score;
                }
                std::cout << "High Score: " << highscore << std::endl;

                win->close();
                return true;

            }
            clock.restart();

        }
    }
    return false;
}

void Game::handleEvents()
{
    sf::Event event;

    while (win->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            win->close();
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
    updateVisuals();
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
        player->handleCollision(i, gameTime);
        healthCounter.setText("Health: " + std::to_string(player->getHealth()));
        i->handleCollision(player);
        for (Enemy *j : all_enemies)
        {
            j->handleCollision(i, gameTime);
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
            scoreCounter.setText("Score: " + std::to_string(score));
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
    scoreCounter.draw(*win);
    healthCounter.draw(*win);
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

float Game::getScore()
{
    return score;
}

void Game::updateVisuals()
{
    player->updateFlash(gameTime);
    for (int i = 0; i < all_enemies.size(); i++)
    {
        all_enemies[i]->updateFlash(gameTime);
    }
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
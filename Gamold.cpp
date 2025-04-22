#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Player.h"
#include "Character.h"
#include "Entity.h"
#include "Weapon.h"
#include "Bow.h"
#include "Sword.h"
#include "Zombie.h"



class Game
{
private:
    sf::RenderWindow* win;
    Player* player;
    Weapon* weapon;
    Character** all_characters;
    Projectile** all_projectile;
    int projectileCount;
public:
    Game(int sizeX, int sizeY, std::string title){
        win = new sf::RenderWindow(sf::VideoMode(sizeX,sizeY), title);
        all_characters = new Character*[10];
        all_projectile = new Projectile*[10];
        weapon = new Sword(10, 1, 2, 1);
        player = new Player(10,50,50,3,1,weapon);
        all_characters[0] = player;
        for (int i = 1; i < 10; i++) {
            all_characters[i] = new Zombie(5, rand() % sizeX + 10, rand() % sizeY + 10, 1, .1, 10, weapon);
        }
        for (int i = 0; i < 10; i++) {
            all_projectile[i] = new Projectile();
            //std::cout<<"new"<<std::endl;
        }
        projectileCount = 0;
    }
    void run(){
        bool a = 1;
        while (win->isOpen()) {
            sf::Event event;
            
            
            while (win->pollEvent(event))
            {
                if(event.type == sf::Event::Closed) {
                    win-> close();
                } else if(event.type == sf::Event::GainedFocus) {
                std::cout << "Gained" << std::endl;
                a = 1;
                } else if(event.type == sf::Event::LostFocus) { 
                std::cout << "Lost" << std::endl;
                a = 0;
                } else if(event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space) {
                        if (((float)(clock()-player->getWeapon()->getLastAttack()) / CLOCKS_PER_SEC) > player->getWeapon()->getFireRate() && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                            //std::cout << clock() << std::endl;
                            if (projectileCount >= 10) {
                                projectileCount = 0;
                            }
                            Projectile projectileTemp = player->getWeapon()->attack(player->getPosition(),sf::Vector2f(sf::Mouse::getPosition(*win).x,sf::Mouse::getPosition(*win).y));
                            all_projectile[projectileCount] = new Projectile(projectileTemp);
                            projectileCount ++;
                        }    
                    }
                }
            }
            
            if (a) {
                //std::cout << "working";
            player->setPosition(win);
            for (int i = 0; i < 10; i++) {
                
                if (all_characters[i]->getType() == "Player") {
                    all_characters[i]->move(player->getDestination());
                } else if (all_characters[i]->getType() == "Zombie") {
                    all_characters[i]->move(player->getPosition());
            }
            }
            for (int i = 0; i < 10; i++) {
                all_projectile[i]->move(all_projectile[i]->getDestination());
            }
            for (int i = 0; i < 10; i++) {
                if (std::sqrt((all_projectile[i]->getPosition().x-all_projectile[i]->getDestination().x)*(all_projectile[i]->getPosition().x-all_projectile[i]->getDestination().x)+(all_projectile[i]->getPosition().y-all_projectile[i]->getDestination().y)*(all_projectile[i]->getPosition().y-all_projectile[i]->getDestination().y)) < all_projectile[i]->getSpeed()) {
                    delete all_projectile[i];
                    all_projectile[i] = new Projectile();
                }
            }

            win->clear();
            for (int i = 0; i < 10; i++) {
                all_characters[i]->draw(win);
            }
            for (int i = 0; i < 10; i++) {
                all_projectile[i]->draw(win);
            }            
            win->display();
        }
    } }
};

int main()
{
    srand(time(0));
    std::cout<<"hi";
    Game g(100,100,"Slayer");
    g.run();
    return 0;
}
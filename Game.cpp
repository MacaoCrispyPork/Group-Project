#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <string>
#include "Player.h"
#include "Character.h"
#include "Entity.h"
#include "Weapon.h"
#include "Bow.h"
#include "Projectile.h"
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
    Game(int sizeX, int sizeY, std::string title) {
        win = new sf::RenderWindow(sf::VideoMode(sizeX,sizeY), title);
        //Size of these arrays is just a random number probably best to replace with a variable
        all_characters = new Character*[10];
        all_projectile = new Projectile*[10];
        weapon = new Bow(10, 1, 2, 1, 300);
        player = new Player(10,50,50,3,1,weapon);
        all_characters[0] = player;
        //Creating Zombies with randomised position
        for (int i = 1; i < 10; i++) {
            all_characters[i] = new Zombie(5, rand() % sizeX + 10, rand() % sizeY + 10, 1, .1, 10, weapon);
        }
        //Filling the projectile array with generic projectiles
        for (int i = 0; i < 10; i++) {
            all_projectile[i] = new Projectile();
        }
        projectileCount = 0;
    }
    void run(){
        while (win->isOpen()) {
            sf::Event event;
            bool a = 1;
            
            while (win->pollEvent(event))
            {
                if(event.type == sf::Event::Closed) {
                    win-> close();
                //The gained focus and lost focus is just some code I added so the game will freeze if it is not the main window. But I broke the code at some point so idk.
                } else if(event.type == sf::Event::GainedFocus) {
                std::cout << "Gained" << std::endl;
                a = 1;
                } else if(event.type == sf::Event::LostFocus) { 
                std::cout << "Lost" << std::endl;
                a = 0;
                //Checking for spacebar being pressed
                } else if(event.type == sf::Event::KeyPressed) {
                    if (event.key.code == sf::Keyboard::Space) {
                        //Clock() was just a way of getting the time doing some research I might change to sf::Clock. Dividing the time since the last attack by CLOCKS_PER_SEC converts it from clock units to seconds.
                        //If the time since the last attack greater than the firerate of the weapon the player can shoot
                        if (((float)(clock()-player->getWeapon()->getLastAttack()) / CLOCKS_PER_SEC) > player->getWeapon()->getFireRate() && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                            //just resets the counter of the array definetely better ways to do this
                            if (projectileCount >= 10) {
                                projectileCount = 0;
                            }
                            //creating the new projectile. isPlayer is true for this as only the player has it.
                            all_projectile[projectileCount] = new Projectile(player->getWeapon()->attack(player->getPosition(),sf::Vector2f(sf::Mouse::getPosition(*win).x,sf::Mouse::getPosition(*win).y), 1));
                            projectileCount ++;

                        }    
                    }
                }

            }
        
            if (a) {
                

            player->setPosition(win);
            for (int i = 0; i < 10; i++) {
                
                if (all_characters[i]->getType() == "Player") {
                    all_characters[i]->move(player->getDestination());
                } else if (all_characters[i]->getType() == "Zombie") {
                    all_characters[i]->move(player->getPosition());
            }
            }
            //Basic movement code
            for (int i = 0; i < 10; i++) {
                all_projectile[i]->move(all_projectile[i]->getDestination());
            }
            
            for (int i = 0; i < 10; i++) {
                if (std::sqrt((all_projectile[i]->getPosition().x-all_projectile[i]->getDestination().x)*(all_projectile[i]->getPosition().x-all_projectile[i]->getDestination().x)+(all_projectile[i]->getPosition().y-all_projectile[i]->getDestination().y)*(all_projectile[i]->getPosition().y-all_projectile[i]->getDestination().y)) < all_projectile[i]->getSpeed()) {
                    delete all_projectile[i];
                    all_projectile[i] = new Projectile();
                }
            }
            //Damage actually means nothing right now but I think this code works
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (all_characters[i]->checkCollision(all_projectile[j])) {
                        std::cout << clock() / CLOCKS_PER_SEC << " : " << all_characters[i]->getType() << " " << i << " collided with " << all_projectile[j]->getType() << " " << j << std::endl;
                        all_characters[i]->takeDamage(all_projectile[j]->getDamage());
                    };
                }
            }   
            //Here is where we will delete projectile after it hits something
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 10; j++) {
                    if (all_projectile[i]->checkCollision(all_characters[j])) {
                        std::cout << float(clock() / CLOCKS_PER_SEC) << " : " << all_projectile[i]->getType() << " " << i << " collided with " << all_characters[j]->getType() << " " << j << std::endl;
                    };
                }
            }            
       
            win->clear();
            //Cycling through array to draw them

            for (int i = 0; i < 10; i++) {
                all_characters[i]->draw(win);
            }
            
            for (int i = 0; i < 10; i++) {
                all_projectile[i]->draw(win);
            }  
            win->display();

        }
    }
 }
};

int main()
{
    srand(time(0));
    Game g(500,500,"Slayer");
    g.run();

    return 0;
}
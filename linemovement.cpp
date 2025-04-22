#include <SFML/Graphics.hpp>
#include <thread>
#include <cmath>
#include <math.h>
using namespace std::chrono_literals;
float findLength(sf::Vector2f vector) {
    float length = std::sqrt(vector.x*vector.x+vector.y*vector.y);
    return length;
};
int main()
{
    sf::RenderWindow window(sf::VideoMode({900, 900}), "SFML works!");
    sf::CircleShape shape2(10.f,3);
    shape2.setFillColor(sf::Color::Red);
    shape2.setOrigin(sf::Vector2f(5,5));
    shape2.setPosition(sf::Vector2f(150,150));
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    //shape.setOrigin(sf::Vector2f(5,5));
    shape.setPosition(sf::Vector2f(100,100));
    sf::Font font;
    font.loadFromFile("Ubuntu-R.ttf");
    sf::Text text("Hello World",font,10);
    sf::RectangleShape rect(sf::Vector2f(30.f,1.f));
    text.setFillColor(sf::Color::White);
    text.setPosition(200,200);
    float speed = 5.f;
    sf::Vector2f destination(0.f,0.f);

    while (window.isOpen()) {

        sf::Event event;
    while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && speed >= 0.f) {
            speed -= 1.f;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            speed += 1.f;
        }
        
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            destination = sf::Vector2f(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
        }
        sf::Vector2f movement(destination-shape.getPosition());


        double X = sf::Mouse::getPosition(window).x;
        double Y = sf::Mouse::getPosition(window).y;

        if (movement.x != 0.f || movement.y != 0.f) {
            float length = std::sqrt(movement.x*movement.x + movement.y*movement.y);
            movement /= length;
            movement *= speed; 
        }
        text.setString("Moving in: " + std::to_string(movement.x) + ", " + std::to_string(movement.y));

        if (std::sqrt((shape.getPosition().x-destination.x)*(shape.getPosition().x-destination.x)+(shape.getPosition().y-destination.y)*(shape.getPosition().y-destination.y)) > speed/2) {
            shape.move(movement);
        }
        rect.setPosition(shape.getPosition()+sf::Vector2f(10.f,10.f));
        double XPose = rect.getPosition().x;
        double YPose = rect.getPosition().y;
        if (X >= XPose) {
            rect.setRotation((180/3.14159)*atan((Y-YPose)/(X-XPose)));
        } else {
            rect.setRotation(180+(180/3.14159)*atan((Y-YPose)/(X-XPose)));
        }

        float distance = std::sqrt((XPose-sf::Mouse::getPosition(window).x)*(XPose-sf::Mouse::getPosition(window).x)+(YPose-sf::Mouse::getPosition(window).y)*(YPose-sf::Mouse::getPosition(window).y));
        rect.setSize(sf::Vector2f(distance,1.f));
        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.draw(text);
        window.draw(rect);

        window.display();
        std::this_thread::sleep_for(16.6666666667ms);
        
    }

}
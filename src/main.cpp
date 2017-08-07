#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Server.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Server server = Server();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
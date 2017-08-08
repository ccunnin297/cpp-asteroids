#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <memory>
#include <iostream>

#include "Server.h"
#include "Client.h"

int main() {
    std::cout << "test" << std::endl;
    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    const unsigned short port = 50001;

    auto server = std::make_unique<Server>(port);
    server->start();

    auto client = std::make_unique<Client>();
    client->connectToServer("127.0.0.1", port);

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
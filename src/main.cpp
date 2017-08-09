#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <memory>
#include <iostream>

#include "Server.h"
#include "Client.h"
#include "ClientGame.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");
    
    const unsigned short port = 50001;

    Server server(port);
    server.start();

    Client client;
    client.connectToServer("127.0.0.1", port);

    // auto clientGame = std::make_unique<ClientGame>();
    ClientGame clientGame;

    //input -> client -> server -> servergame
    //servergame -> server -> client -> clientgame

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //send inputs to server
        // client->sendInputs(inputs);

        //update client from server
        // clientGame->updateFromClient(client);

        //Draw GUI
        window.clear();
        clientGame.draw(window);
        window.display();
    }

    return 0;
}
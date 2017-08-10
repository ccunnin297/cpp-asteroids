#include "Client.h"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include <thread>

#include <json.hpp>

Client::Client()
{
    m_socket = std::make_unique<sf::TcpSocket>();
    m_game = std::make_unique<Game>();
};

//TCP
void Client::connectToServer(sf::IpAddress address, unsigned short port)
{
    sf::Socket::Status status = m_socket->connect(address, port);
    if (status != sf::Socket::Done) {
        //error
        std::cout << "error connecting on client" << std::endl;
    } else {
        std::cout << "client connected" << std::endl;
        std::thread t1([=] { listen(); });;
        t1.detach();
    }
};

void Client::listen()
{
    char data[1000];
    std::size_t received;
    while (true) {
        //wait until packet is received
        if (m_socket->receive(data, 1000, received) != sf::Socket::Done) {
            //error
        }
        std::string strData(data);
        nlohmann::json jsonState = nlohmann::json::parse(strData);

        m_game->setState(jsonState);
    }
};

void Client::run()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Draw GUI
        window.clear();
        draw(window);
        window.display();
    }
};

void Client::draw(sf::RenderWindow &window)
{
    m_game->draw(window);
}
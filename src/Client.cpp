#include "Client.h"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include <thread>

Client::Client()
{
    m_socket = std::make_unique<sf::TcpSocket>();
    m_game = std::make_unique<Game>();
    m_inputs = std::make_unique<Inputs>();
};

//TCP
void Client::connectToServer(sf::IpAddress address, unsigned short port)
{
    sf::Socket::Status status = m_socket->connect(address, port);
    if (status != sf::Socket::Done) {
        std::cout << "error connecting on client" << std::endl;
    } else {
        std::cout << "client connected to server" << std::endl;
        std::thread t1([=] { listen(); });;
        t1.detach();
    }
};

void Client::listen()
{
    while (true) {
        //wait until packet is received
        char data[100000];
        std::size_t received;
        if (m_socket->receive(data, 100000, received) != sf::Socket::Done) {
            //error
        }
        // std::string strData(data);
        GameState gameState;
        gameState.ParseFromString(data);
        m_game->setState(gameState);
    }
};

void Client::run()
{
    sf::RenderWindow window(sf::VideoMode(2000, 1000), "SFML works!");

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() >= 33) { //30 ticks per second
            updateInputs();
            m_game->run();
            updateServer();
            draw(window);
            clock.restart();
        }

        //Draw GUI
        // if (elapsed.asMilliseconds() >= 33) { //30 frames per second
            
        // }
    }
};

void Client::draw(sf::RenderWindow &window)
{
    window.clear();
    m_game->draw(window);
    window.display();
};

void Client::updateInputs()
{
    m_inputs->update();
};

void Client::updateServer()
{
    //send updates to server
    //check for server first
    // if (m_socket) {
    //     nlohmann::json jsonState = m_game->getState();
    //     std::string strData = jsonState.dump();
    //     if (m_socket->send(strData.c_str(), 1000) != sf::Socket::Done) {
    //         //Error
    //     }
    // }
};
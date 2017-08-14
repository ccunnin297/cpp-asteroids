#include "Server.h"

#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include <thread>

Server::Server(unsigned short port)
{
    m_port = port;
    m_listener = std::make_unique<sf::TcpListener>();
    m_game = std::make_unique<Game>();
};

void Server::start()
{
    // bind the listener to a port
    if (m_listener->listen(m_port) != sf::Socket::Done)
    {
        // error... 
        std::cout << "error listening to port" << std::endl;
        return;
    }
    std::cout << "done" << std::endl;
    std::thread t1([=] { waitForClients(); });
    std::thread t2([=] { run(); });;
    t1.detach();
    t2.detach();

    m_game->addEntities();
}

void Server::waitForClients()
{
    while(true) {
        // accept a new connection
        auto client = std::make_unique<sf::TcpSocket>();
        if (m_listener->accept(*client) != sf::Socket::Done)
        {
            std::cout << "error connecting on server" << std::endl;
        } else {
            m_socket = std::move(client);
            std::cout << "server connected to client" << std::endl;
        }
    }
};

void Server::run()
{
    sf::Clock clock;
    while(true) {
        sf::Time elapsed = clock.getElapsedTime();
        
        if (elapsed.asMilliseconds() >= 33) { //30 ticks per second
        // if (elapsed.asMilliseconds() >= 1000) { //1 tick per second
            m_game->run();
            updateClient();
            clock.restart();
        }
        
    }
};

void Server::updateClient()
{
    //check for client first
    if (m_socket) {
        auto gameState = m_game->getState();
        std::string strData;
        gameState.SerializeToString(&strData);
        sf::Packet packet;
        packet << strData;
        if (m_socket->send(packet) != sf::Socket::Done) {
            //Error
        }
    }
};
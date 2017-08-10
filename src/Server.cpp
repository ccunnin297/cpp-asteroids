#include "Server.h"

#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include <thread>

#include <json.hpp>

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
            // std::cout << "error connecting on server" << std::endl;
            return;
        } else {
            m_socket = std::move(client);
            std::cout << "server connected" << std::endl;
        }
    }
};

void Server::run()
{
    sf::Clock clock;
    while(true) {
        sf::Time elapsed = clock.getElapsedTime();
        
        // if (elapsed.asMilliseconds() >= 33) { //30 fps
        if (elapsed.asMilliseconds() >= 1000) {
            //run game
            m_game->run();
            updateClient();
            //restart timer
            clock.restart();
        }
        
    }
};

void Server::updateClient()
{
    //communicate updates to client
    //check for client first
    if (m_socket) {
        nlohmann::json jsonState = m_game->getState();
        std::string strData = jsonState.dump();
        if (m_socket->send(strData.c_str(), 1000) != sf::Socket::Done) {
            //Error
        }
    }
};
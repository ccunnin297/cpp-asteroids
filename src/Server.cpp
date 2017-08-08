#include "Server.h"

#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include <thread>

Server::Server(unsigned short port)
{
    m_port = port;
    m_listener = std::make_unique<sf::TcpListener>();  
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
    std::thread t2([=] { run(); })
    t1.detach();
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
            std::cout << "server connected" << std::endl;
        }
    }
};

void Server::run()
{
    
}
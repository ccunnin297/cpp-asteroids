#pragma once

#include <SFML/Network.hpp>
#include <memory>

class Server
{
    public:
        Server(unsigned short port);
        void start();
    private:
        void waitForClients();
        void run();
        
        std::unique_ptr<sf::TcpSocket> m_socket;
        std::unique_ptr<sf::TcpListener> m_listener;
        unsigned short m_port;
};
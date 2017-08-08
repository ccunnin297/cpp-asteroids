#pragma once

#include <SFML/Network.hpp>
#include <memory>

class Client
{
    public:
        Client();
        void connectToServer(sf::IpAddress address, unsigned short port);
    private:
        std::unique_ptr<sf::TcpSocket> m_socket;
};
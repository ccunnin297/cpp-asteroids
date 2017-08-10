#pragma once

#include <SFML/Network.hpp>
#include <memory>

#include "Game.h"

class Client
{
    public:
        Client();
        void connectToServer(sf::IpAddress address, unsigned short port);
        void listen();
        void run();
        void draw(sf::RenderWindow &window);
    private:
        std::unique_ptr<sf::TcpSocket> m_socket;
        std::unique_ptr<Game> m_game;
};
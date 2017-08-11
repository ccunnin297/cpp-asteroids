#pragma once

#include <SFML/Network.hpp>
#include <memory>

#include "Game.h"
#include "Inputs.h"

class Client
{
    public:
        Client();

        void connectToServer(sf::IpAddress address, unsigned short port);
        void run();
    private:
        void listen();
        void draw(sf::RenderWindow &window);
        void updateInputs();
        void updateServer();

        std::unique_ptr<sf::TcpSocket> m_socket;
        std::unique_ptr<Game> m_game;
        std::unique_ptr<Inputs> m_inputs;
};
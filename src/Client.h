#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <thread>

#include "ClientGame.h"
#include "Inputs.h"

class Client
{
    public:
        Client();

        void connectToServer(sf::IpAddress address, unsigned short port);
        void run();
    private:

        void listen();
        void updateInputs(sf::Event event);
        void updateServer();

        std::unique_ptr<sf::TcpSocket> m_socket;
        std::unique_ptr<ClientGame> m_game;
        std::unique_ptr<Inputs> m_inputs;

        std::unique_ptr<std::thread> m_listenerThread;
};
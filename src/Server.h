#pragma once

#include <SFML/Network.hpp>
#include <memory>
#include <thread>

#include "Game.h"

class Server
{
    public:
        Server(unsigned short port);
        void start();
    private:
        void waitForClients();
        void run();
        void updateClient();
        void listen();
        
        std::unique_ptr<Game> m_game;
        std::unique_ptr<sf::TcpSocket> m_socket;
        std::unique_ptr<sf::TcpListener> m_listener;
        unsigned short m_port;

        std::unique_ptr<std::thread> m_clientThread;
        std::unique_ptr<std::thread> m_runnerThread;
        std::unique_ptr<std::thread> m_listenerThread;
};
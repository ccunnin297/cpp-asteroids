#pragma once

#include <SFML/Network.hpp>
#include <memory>
#include <thread>

#include "Game.h"
#include "Player.h"

class Server
{
    public:
        Server(unsigned short port);
        ~Server();
        
        void start();
    private:
        void waitForClients();
        void run();
        void updateClient();
        void listen();
        void addPlayer(std::unique_ptr<sf::TcpSocket> socket);
        void removePlayer(std::shared_ptr<Player> player);

        std::unique_ptr<std::thread> runThread(std::function<void(void)> const& lambda);
        std::unique_ptr<std::thread> runTickrateLimitedThread(std::function<void(void)> const& lambda);
        
        std::unique_ptr<Game> m_game;
        std::unique_ptr<sf::SocketSelector> m_socketSelector;
        std::vector<std::shared_ptr<Player>> m_players;
        std::unique_ptr<sf::TcpListener> m_listener;
        unsigned short m_port;

        bool m_running;

        std::unique_ptr<std::thread> m_clientThread;
        std::unique_ptr<std::thread> m_runnerThread;
        std::unique_ptr<std::thread> m_listenerThread;
};
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <thread>

#include "Server.h"
#include "MainMenu.h"
#include "ClientGame.h"
#include "Inputs.h"

enum ClientPhase {
    Menu,
    Game
};

class Client
{
    public:
        Client();

        void startServer();
        void connectToServer(sf::IpAddress address, unsigned short port);
        void run();

        void connectToGame(sf::IpAddress address);
        void hostGame();

        void openMainMenu();
    private:
        void openGame();

        void listen();
        void updateInputs(sf::Event event);
        void updateServer();

        ClientPhase m_phase;

        std::unique_ptr<Server> m_server;
        std::unique_ptr<sf::TcpSocket> m_socket;
        std::unique_ptr<ClientGame> m_game;
        std::unique_ptr<MainMenu> m_mainMenu;
        std::unique_ptr<Inputs> m_inputs;

        std::unique_ptr<std::thread> m_listenerThread;
};
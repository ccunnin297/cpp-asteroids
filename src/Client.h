#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <thread>
#include <queue>

#include "Game.h"
#include "Inputs.h"
#include "Camera.h"

class Client
{
    public:
        Client();
        ~Client();

        void connectToServer(sf::IpAddress address, unsigned short port);
        void run(sf::RenderWindow& window);
    private:

        void startListener();
        void listen();
        void updateInputs(sf::Event event);
        void updateServer();
        void disconnectFromServer();

        std::unique_ptr<sf::TcpSocket> m_socket;
        std::unique_ptr<Game> m_game;
        std::unique_ptr<Camera> m_camera;
        std::unique_ptr<Inputs> m_inputs;

        volatile bool m_listening;

        std::unique_ptr<std::thread> m_listenerThread;

        std::queue<GameState> m_pendingGameStates;
};
#include "Client.h"

#include "GameValues.h"

#include <iostream>

Client::Client()
{
    m_socket = std::make_unique<sf::TcpSocket>();
    m_game = std::make_unique<ClientGame>(this);
    m_mainMenu = std::make_unique<MainMenu>(this);
    m_inputs = std::make_unique<Inputs>();

    m_phase = Menu;
};

void Client::startServer()
{
    m_server = std::make_unique<Server>(NETWORK_PORT);
    m_server->start();
};

//TCP
void Client::connectToServer(sf::IpAddress address, unsigned short port)
{
    sf::Socket::Status status = m_socket->connect(address, port);
    if (status != sf::Socket::Done) {
        std::cout << "error connecting on client" << std::endl;
    } else {
        std::cout << "client connected to server" << std::endl;
        m_listenerThread = std::make_unique<std::thread>([=] { listen(); });
        m_listenerThread->detach();
    }
};

void Client::listen()
{
    sf::Packet packet;
    std::string strData;
    GameState gameState;
    while (true) {
        if (m_socket->receive(packet) != sf::Socket::Done) {
            //error
        } else {
            packet >> strData;
            gameState.ParseFromString(strData);
            m_game->setState(gameState);
        }
    }
};

void Client::run()
{
    sf::RenderWindow window(sf::VideoMode(GAME_BOUNDS_X, GAME_BOUNDS_Y), "cpp-asteroids");
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                updateInputs(event);
            }
        }

        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() >= 33) { //30 ticks per second
            window.clear();

            switch (m_phase) {
                case Game:
                    m_game->run();
                    m_game->cleanup();
                    m_game->draw(window);
                    break;
                case Menu:
                    m_mainMenu->acceptInputs(m_inputs.get());
                    m_mainMenu->run();
                    m_mainMenu->draw(window);
                    break;
                default:
                    break;
            }
            
            window.display();
            clock.restart();
        }
    }    
};

void Client::hostGame()
{
    startServer();
    connectToGame("127.0.0.1");
};

void Client::connectToGame(sf::IpAddress address)
{
    connectToServer(address, NETWORK_PORT);
    openGame();
};

void Client::openGame()
{
    m_game->reset();
    m_phase = Game;
};

void Client::openMainMenu()
{
    m_mainMenu->reset();
    m_phase = Menu;
};

void Client::updateInputs(sf::Event event)
{
    m_inputs->update(event);
    updateServer();
};

void Client::updateServer()
{
    // check for server first
    if (m_socket) {
        auto inputState = m_inputs->getState();
        std::string strData;
        inputState.SerializeToString(&strData);
        sf::Packet packet;
        packet << strData;
        if (m_socket->send(packet) != sf::Socket::Done) {
            //Error
        }
    }
};
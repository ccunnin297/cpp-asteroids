#include "Client.h"

#include "GameValues.h"

#include <iostream>

Client::Client()
{
    m_socket = std::make_unique<sf::TcpSocket>();
    m_game = std::make_unique<Game>();
    m_inputs = std::make_unique<Inputs>();
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
            
            m_game->run();
            m_game->cleanup();
            draw(window);
            clock.restart();
        }

        //Draw GUI
        // if (elapsed.asMilliseconds() >= 33) { //30 frames per second
            
        // }
    }
};

void Client::draw(sf::RenderWindow &window)
{
    window.clear();
    m_game->draw(window);
    window.display();
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
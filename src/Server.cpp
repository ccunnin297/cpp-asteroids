#include "Server.h"

#include <iostream>

Server::Server(unsigned short port)
{
    m_port = port;
    m_listener = std::make_unique<sf::TcpListener>();
    m_game = std::make_unique<Game>();
};

void Server::start()
{
    // bind the listener to a port
    if (m_listener->listen(m_port) != sf::Socket::Done)
    {
        // error... 
        std::cout << "error listening to port" << std::endl;
        return;
    }
    std::cout << "server started" << std::endl;

    m_clientThread = std::make_unique<std::thread>([=] { waitForClients(); });
    m_clientThread->detach();
    m_runnerThread = std::make_unique<std::thread>([=] { run(); });
    m_runnerThread->detach();
    m_listenerThread = std::make_unique<std::thread>([=] { listen(); });
    m_listenerThread->detach();

    m_game->addEntities();
}

void Server::waitForClients()
{
    while(true) {
        // accept a new connection
        auto client = std::make_unique<sf::TcpSocket>();
        if (m_listener->accept(*client) != sf::Socket::Done)
        {
            std::cout << "error connecting on server" << std::endl;
        } else {
            m_socket = std::move(client);
            std::cout << "server connected to client" << std::endl;
        }
    }
};

void Server::run()
{
    sf::Clock clock;
    while(true) {
        sf::Time elapsed = clock.getElapsedTime();
        
        if (elapsed.asMilliseconds() >= 33) { //30 ticks per second
        // if (elapsed.asMilliseconds() >= 1000) { //1 tick per second
            m_game->run();
            updateClient();
            clock.restart();
        }
        
    }
};

void Server::updateClient()
{
    //check for client first
    if (m_socket) {
        auto gameState = m_game->getState();
        std::string strData;
        gameState.SerializeToString(&strData);
        sf::Packet packet;
        packet << strData;
        if (m_socket->send(packet) != sf::Socket::Done) {
            //Error
        }
    }
};

void Server::listen()
{
    //Listen for inputs
    InputState inputState;
    std::string strData;
    sf::Packet packet;
    while (true) {
        if (m_socket) {
            if (m_socket->receive(packet) != sf::Socket::Done) {
                //error
            } else {
                packet >> strData;
                inputState.ParseFromString(strData);
                auto inputs = std::make_unique<Inputs>();
                inputs->setState(inputState);
                m_game->enactInputs(std::move(inputs)); 
            }
        }
    }
};
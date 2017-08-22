#include "Server.h"

#include <iostream>

Server::Server(unsigned short port)
{
    m_port = port;
    m_listener = std::make_unique<sf::TcpListener>();
    m_socketSelector = std::make_unique<sf::SocketSelector>();
    m_socketSelector->add(*m_listener);
    m_game = std::make_unique<Game>();
};

Server::~Server()
{
    m_running = false;
    m_listener->close();
    for (auto& player : m_players) {
        player->getSocket()->disconnect();
    }
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

    m_running = true;

    m_clientThread = std::make_unique<std::thread>([=] { waitForClients(); });
    m_clientThread->detach();
    m_runnerThread = std::make_unique<std::thread>([=] { run(); });
    m_runnerThread->detach();
    m_listenerThread = std::make_unique<std::thread>([=] { listen(); });
    m_listenerThread->detach();
}

void Server::waitForClients()
{
    while(m_running) {
        // accept a new connection
        auto socket = std::make_unique<sf::TcpSocket>();
        if (m_listener->accept(*socket) != sf::Socket::Done)
        {
            std::cout << "error connecting on server" << std::endl;
        } else {
            m_socketSelector->add(*socket);
            addPlayer(std::move(socket));
            std::cout << "server connected to client" << std::endl;
        }
    }
};

void Server::run()
{
    sf::Clock clock;
    while(m_running) {
        sf::Time elapsed = clock.getElapsedTime();
        
        if (elapsed.asMilliseconds() >= 33) { //30 ticks per second
        // if (elapsed.asMilliseconds() >= 1000) { //1 tick per second
            m_game->run();
            updateClient();
            m_game->cleanup();
            clock.restart();
        }
        
    }
};

void Server::updateClient()
{
    //check for client first
    for (auto& player : m_players) {
        auto gameState = m_game->getState();
        std::string strData;
        gameState.SerializeToString(&strData);
        sf::Packet packet;
        packet << strData;
        sf::TcpSocket* socket = player->getSocket();
        if (socket->send(packet) != sf::Socket::Done) {
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
    while (m_running) {
        if (m_socketSelector->wait(sf::milliseconds(30))) {
            for (auto &player : m_players) {
                sf::TcpSocket* socket = player->getSocket();
                if (m_socketSelector->isReady(*socket)) {
                    if (socket->receive(packet) != sf::Socket::Done) {
                        //error
                        std::cout << "Error receiving packet on server" << std::endl;
                    } else {
                        packet >> strData;
                        inputState.ParseFromString(strData);
                        player->setInputState(inputState);
                        player->setNewInputs(true);
                    }
                }
            }
        }
    }
};

void Server::addPlayer(std::unique_ptr<sf::TcpSocket> socket)
{
    auto player = std::make_shared<Player>();
    player->setSocket(std::move(socket));
    m_game->addPlayer(player);
    m_players.emplace_back(player);
};
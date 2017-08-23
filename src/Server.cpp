#include "Server.h"

#include "GameValues.h"

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
        auto status = m_listener->accept(*socket);
        switch (status) {
            case sf::Socket::Done:
                if (m_players.size() < MAX_PLAYERS) {
                    m_socketSelector->add(*socket);
                    addPlayer(std::move(socket));
                    std::cout << "server connected to client" << std::endl;
                } else {
                    //TODO: send message back to client indicating max number reached
                    std::cout << "Reached max number of players, rejecting client connection" << std::endl;
                }
                break;
            default:
                std::cout << "error connecting on server" << std::endl;
                break;
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
        auto status = socket->send(packet);
        switch (status) {
            case sf::Socket::Disconnected:
                std::cout << "Client disconnected" << std::endl;
                removePlayer(player);
                break;
            case sf::Socket::Done:
                //success
                break;
            default:
                //Error
                std::cout << "Error sending packet to client" << std::endl;
                break;
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
                    auto status = socket->receive(packet);
                    switch (status) {
                        case sf::Socket::Disconnected:
                            std::cout << "Client disconnected" << std::endl;
                            removePlayer(player);
                            break;
                        case sf::Socket::Done:
                            packet >> strData;
                            inputState.ParseFromString(strData);
                            player->setInputState(inputState);
                            player->setNewInputs(true);
                            break;
                        default:
                            //Error
                            std::cout << "Error receiving packet on server" << std::endl;
                            break;
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

void Server::removePlayer(std::shared_ptr<Player> player)
{
    m_socketSelector->remove(*player->getSocket());
    m_game->removePlayer(player);
    m_players.erase(std::remove(m_players.begin(), m_players.end(), player));
}
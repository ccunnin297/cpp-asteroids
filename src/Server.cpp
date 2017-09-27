#include "Server.h"

#include "GameValues.h"

#include "Logger.h"

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
        Logger::log("error listening to port");
        return;
    }
    Logger::log("server started");

    m_running = true;

    m_clientThread = runTickrateLimitedThread([=] { waitForClients(); });
    m_runnerThread = runTickrateLimitedThread([=] { run(); });
    m_listenerThread = runThread([=] { listen(); });
}

std::unique_ptr<std::thread> Server::runThread(std::function<void(void)> const& lambda)
{
    auto thread = std::make_unique<std::thread>([=] {
        while(m_running) {
            lambda();
        }
    });
    thread->detach();
    return thread;
};

std::unique_ptr<std::thread> Server::runTickrateLimitedThread(std::function<void(void)> const& lambda)
{
    auto thread = std::make_unique<std::thread>([=] {
        sf::Clock clock;
        while(m_running) {
            sf::Time elapsed = clock.getElapsedTime();
            if (elapsed.asMilliseconds() >= TICKRATE_MS) {
                lambda();
                clock.restart();
                sf::sleep(sf::milliseconds(TICKRATE_MS));
            }
        }
    });
    thread->detach();
    return thread;
};

void Server::waitForClients()
{
    // accept a new connection
    auto socket = std::make_unique<sf::TcpSocket>();
    auto status = m_listener->accept(*socket);
    switch (status) {
        case sf::Socket::Done:
            if (m_players.size() < MAX_PLAYERS) {
                m_socketSelector->add(*socket);
                addPlayer(std::move(socket));
                Logger::log("server connected to client");
            } else {
                //TODO: send message back to client indicating max number reached
                Logger::log("Reached max number of players, rejecting client connection");
            }
            break;
        default:
            Logger::log("error connecting on server");
            break;
    }
};

void Server::run()
{
    m_game->run();
    updateClient();
    m_game->cleanup();
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
                Logger::log("Client disconnected");
                removePlayer(player);
                break;
            case sf::Socket::Done:
                //success
                break;
            default:
                //Error
                Logger::log("Error sending packet to client");
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
    if (m_socketSelector->wait(sf::milliseconds(TICKRATE_MS))) {
        for (auto &player : m_players) {
            sf::TcpSocket* socket = player->getSocket();
            if (m_socketSelector->isReady(*socket)) {
                auto status = socket->receive(packet);
                switch (status) {
                    case sf::Socket::Disconnected:
                        Logger::log("Client disconnected");
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
                        Logger::log("Error receiving packet on server");
                        break;
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
#include "Client.h"

#include "GameValues.h"

#include "Logger.h"

Client::Client()
{
    m_socket = std::make_unique<sf::TcpSocket>();
    m_game = std::make_unique<Game>();
    m_inputs = std::make_unique<Inputs>();
    m_camera = std::make_unique<Camera>();
};

Client::~Client()
{
    disconnectFromServer();
};

//TCP
void Client::connectToServer(sf::IpAddress address, unsigned short port)
{
    sf::Socket::Status status = m_socket->connect(address, port);
    if (status != sf::Socket::Done) {
        Logger::log("error connecting on client");
    } else {
        Logger::log("client connected to server");
        startListener();
    }
};

void Client::startListener()
{
    m_listening = true;
    m_listenerThread = std::make_unique<std::thread>([=] {
        listen();
    });
    m_listenerThread->detach();
};

void Client::listen()
{
    sf::Packet packet;
    std::string strData;
    GameState gameState;
    while(m_listening) {
        auto status = m_socket->receive(packet);
        switch (status) {
            case sf::Socket::Disconnected:
                Logger::log("Server disconnected");
                disconnectFromServer();
                break;
            case sf::Socket::Done:
                packet >> strData;
                gameState.ParseFromString(strData);
                m_pendingGameStates.push(gameState);
                break;
            default:
                //Errors
                Logger::log("error receiving updates from server");
                break;
        }
    }
};

void Client::run(sf::RenderWindow& window)
{
    window.setKeyRepeatEnabled(false);

    sf::Clock clock;
    while (window.isOpen())
    {
        double deltaTime = clock.getElapsedTime().asMilliseconds();
        if (deltaTime >= TICKRATE_MS) {
            double deltas = deltaTime / TICKRATE_MS;
            
            while (!m_pendingGameStates.empty()) {
                m_game->setState(m_pendingGameStates.front());
                m_pendingGameStates.pop();
            }

            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
    
                if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
                    updateInputs(event);
                }
            }

            m_game->run(deltas);
            m_game->cleanup();

            window.clear();
            m_game->draw(*m_camera, window);
            window.display();

            clock.restart();
            sf::sleep(sf::milliseconds(TICKRATE_MS));
        }
    }    
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
        auto status = m_socket->send(packet);
        switch (status) {
            case sf::Socket::Disconnected:
                Logger::log("Server disconnected");
                disconnectFromServer();
                break;
            case sf::Socket::Done:
                //Success
                break;
            default:
                //Errors
                Logger::log("Error sending inputs to server");
                break;
        }
    }
};

void Client::disconnectFromServer()
{
    m_listening = false;
    m_socket->disconnect();
};
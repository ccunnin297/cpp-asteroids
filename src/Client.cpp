#include "Client.h"

#include "GameValues.h"

#include "Logger.h"

Client::Client()
{
    m_socket = std::make_unique<sf::TcpSocket>();
    m_game = std::make_unique<ClientGame>();
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
    ConnectionState connectionState;
    while(m_listening) {
        auto status = m_socket->receive(packet);
		//Lock connectionStates in order to prevent game loop from reading too early
		std::lock_guard<std::mutex> lock(m_pendingConnectionStatesLock);
        switch (status) {
            case sf::Socket::Disconnected:
                Logger::log("Server disconnected");
                disconnectFromServer();
                break;
            case sf::Socket::Done:
                packet >> strData;
                connectionState.ParseFromString(strData);
                m_pendingConnectionStates.push(connectionState);
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
            
			//Lock connectionStates in order to prevent game loop from reading too early
			std::lock_guard<std::mutex> lock(m_pendingConnectionStatesLock);
            while (!m_pendingConnectionStates.empty()) {
                ConnectionState nextState = m_pendingConnectionStates.front();
                GameState gameState = nextState.gamestate();

                m_game->m_player->setShipId(nextState.playerstate().shipid());

                m_game->setState(gameState);
                m_pendingConnectionStates.pop();
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

            window.clear(sf::Color::Blue);
            sf::RectangleShape rectangle(sf::Vector2f(GAME_BOUNDS_X, GAME_BOUNDS_Y));
            rectangle.setPosition(0, 0);
            rectangle.setFillColor(sf::Color::Black);
            window.draw(rectangle);
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
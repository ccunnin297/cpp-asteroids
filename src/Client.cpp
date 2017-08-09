#include "Client.h"

#include <SFML/Network.hpp>
#include <iostream>
#include <memory>
#include <thread>

Client::Client()
{
    m_socket = std::make_unique<sf::TcpSocket>();
};

//TCP
void Client::connectToServer(sf::IpAddress address, unsigned short port)
{
    sf::Socket::Status status = m_socket->connect(address, port);
    if (status != sf::Socket::Done) {
        //error
        std::cout << "error connecting on client" << std::endl;
    } else {
        std::cout << "client connected" << std::endl;
        std::thread t1([=] { listen(); });;
        t1.detach();
    }
};

void Client::listen()
{
    char data[100];
    std::size_t received;
    while (true) {
        if (m_socket->receive(data, 100, received) != sf::Socket::Done) {
            //error
        }
        //handle
        std::cout << data << std::endl;
    }
};

// void Client::sendData()
// {
//     char data[100] = ...;

//     // TCP socket:
//     if (m_socket.send(data, 100) != sf::Socket::Done)
//     {
//         // error...
//     }

// }
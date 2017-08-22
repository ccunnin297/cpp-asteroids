#pragma once

#include <SFML/Network.hpp>
#include <memory>
#include "utils.h"
#include "Inputs.h"

class Player
{
public:
    Player();

    sf::TcpSocket* getSocket();
    void setSocket(std::unique_ptr<sf::TcpSocket> socket);

    ID getShipId();
    void setShipId(ID shipId);

    bool newInputs();
    void setNewInputs(bool newInputs);

    Inputs* getInputs();    
    void setInputState(InputState inputState);
private:
    std::unique_ptr<sf::TcpSocket> m_socket;
    std::unique_ptr<Inputs> m_inputs;

    bool m_newInputs;
    ID m_shipId;
};
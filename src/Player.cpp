#include "Player.h"

Player::Player()
{
    m_inputs = std::make_unique<Inputs>();
    m_newInputs = false;
    m_shipId = -1;
};

sf::TcpSocket* Player::getSocket()
{
    return m_socket.get();
};

void Player::setSocket(std::unique_ptr<sf::TcpSocket> socket)
{
    m_socket = std::move(socket);
};

ID Player::getShipId()
{
    return m_shipId;
};

void Player::setShipId(ID shipId)
{
    m_shipId = shipId;
};

bool Player::newInputs()
{
    return m_newInputs;
}

void Player::setNewInputs(bool newInputs)
{
    m_newInputs = newInputs;
}

Inputs* Player::getInputs()
{
    return m_inputs.get();
}  

void Player::setInputState(InputState inputState)
{
    m_inputs->setState(inputState);
}
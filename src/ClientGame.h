#pragma once

#include "Game.h"

class Client;

class ClientGame : public Game
{
    public:
        ClientGame(Client* client);
    private:
        Client* m_client;
};
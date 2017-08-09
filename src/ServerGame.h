#pragma once

#include "Entity.h"
#include <memory>

class ServerGame
{
    public:
        ServerGame();
        void run();
    private:
        std::vector<std::unique_ptr<Entity>> m_entities;
};
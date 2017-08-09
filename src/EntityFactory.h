#pragma once

#include "Entity.h"

#include <memory>

class EntityFactory
{
    public:
        EntityFactory();
        std::unique_ptr<Entity> make();
    private:
        unsigned short m_autoIncrement;
};
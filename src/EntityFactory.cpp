#include "EntityFactory.h"

EntityFactory::EntityFactory()
{
    m_autoIncrement = 0;
};

std::unique_ptr<Entity> EntityFactory::make()
{
    ++m_autoIncrement;
    return std::make_unique<Entity>(m_autoIncrement);
};
#include "ServerGame.h"

#include "EntityFactory.h"

ServerGame::ServerGame()
{
    EntityFactory entityFactory = EntityFactory();
    for (int i = 0; i < 5; ++i) {
        auto entity = entityFactory.make();
        entity->m_position = sf::Vector2f(i*100, 0);
        m_entities.emplace_back(std::move(entity));
    }
};

void ServerGame::run()
{
    for (auto it = m_entities.begin(); it != m_entities.end(); ++it) {
        sf::Vector2f pos = (*it)->m_position;
        (*it)->m_position = sf::Vector2f(pos.x, pos.y+0.5);
    }
};
#include "Game.h"

#include "EntityFactory.h"

Game::Game()
{
};

void Game::addEntities()
{
    EntityFactory entityFactory = EntityFactory();
    for (int i = 0; i < 5; ++i) {
        auto entity = entityFactory.make();
        entity->m_position = sf::Vector2f(i*100, 0);
        m_entities.emplace_back(std::move(entity));
    }
}

void Game::run()
{
    for (auto it = m_entities.begin(); it != m_entities.end(); ++it) {
        sf::Vector2f pos = (*it)->m_position;
        (*it)->m_position = sf::Vector2f(pos.x, pos.y+0.5);
    }
};

void Game::draw(sf::RenderWindow &window)
{
    for (auto it = m_entities.begin(); it != m_entities.end(); ++it) {
        sf::CircleShape circle(50);
        circle.setPosition((*it)->m_position);
        circle.setFillColor(sf::Color(100, 250, 50));
        window.draw(circle);
    }
};

void Game::setState(nlohmann::json jsonState)
{
    for (auto jsonIt = jsonState.begin(); jsonIt != jsonState.end(); ++jsonIt) {
        unsigned short id = (*jsonIt)["id"];
        std::cout << "trying to find id:" << id << std::endl;

        //Find entity with matching id
        auto entIt = find_if(m_entities.begin(), m_entities.end(), 
            [id](std::unique_ptr<Entity>& entity) {
                return entity->m_id == id;
            });

        if (entIt != m_entities.end()) {
            //Found
            std::cout << "found" << std::endl;
            (*entIt)->setState(*jsonIt);
        } else {
            //New entity, add to the game
            std::cout << "not found, creating new entity" << std::endl;
            auto newEntity = std::make_unique<Entity>(*jsonIt);
            m_entities.emplace_back(std::move(newEntity));
        }
    }
}

nlohmann::json Game::getState()
{
    nlohmann::json jsonState = {};
    for (auto it = m_entities.begin(); it != m_entities.end(); ++it) {
        auto entityState = (*it)->getState();
        jsonState.push_back(entityState);
    }
    return jsonState;
}
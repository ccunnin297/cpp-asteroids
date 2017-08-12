#include "Game.h"

#include "EntityFactory.h"

#include <iostream>

Game::Game()
{
    m_inputs = std::make_unique<Inputs>();
    m_inputFunctions = {
        {InputKey::Forward, std::bind(&Game::moveForward, this)}
    };
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

void Game::setInputState(u_int32_t inputState)
{
    m_inputs->setState(inputState);
}

void Game::moveForward()
{

};

void Game::enactInputs()
{
    for (auto const& it : m_inputFunctions) {
        if (m_inputs->isKeyPressed(it.first)) {
            it.second();
        }
    }
}

void Game::run()
{
    m_inputs->update();

    for (auto& it : m_entities) {
        sf::Vector2f pos = it->m_position;
        it->m_position = sf::Vector2f(pos.x, pos.y+0.5);
    }
};

void Game::draw(sf::RenderWindow &window)
{
    for (auto& it : m_entities) {
        sf::CircleShape circle(50);
        circle.setPosition(it->m_position);
        circle.setFillColor(sf::Color(100, 250, 50));
        window.draw(circle);
    }
};

void Game::setState(GameState& gameState)
{
    auto entityStates = gameState.entities();
    for (auto& entStateIt : entityStates) {
        unsigned short id = entStateIt.id();

        //Find entity with matching id
        auto entIt = std::find_if(
            m_entities.begin(), 
            m_entities.end(), 
            [&](std::unique_ptr<Entity> const& entity) {
                return entity.get()->m_id == id;
            });

        if (entIt != m_entities.end()) {
            //Found
            (*entIt)->setState(entStateIt);
        } else {
            //New entity, add to the game
            auto newEntity = std::make_unique<Entity>(entStateIt);
            m_entities.emplace_back(std::move(newEntity));
        }
    }
}

std::unique_ptr<GameState> Game::getState()
{
    auto gameState = std::make_unique<GameState>();
    for (auto& it : m_entities) {
        auto entityState = it->getState();
        EntityState* newEntityState = gameState->add_entities();
        newEntityState->CopyFrom(entityState);
    }
    return gameState;
}
#include "Game.h"

#include "EntityFactory.h"

#include <iostream>

Game::Game()
{
    m_inputPressedFunctions = {
        {InputKey::Forward, std::bind(&Game::moveForward, this)}
    };
    m_inputReleasedFunctions = {
        {InputKey::Forward, std::bind(&Game::stopMovingForward, this)}
    };
    m_inputDownFunctions = {
    };
};

void Game::addEntities()
{
    EntityFactory entityFactory = EntityFactory();
    for (int i = 0; i < 5; ++i) {
        std::unique_ptr<Entity> entity = entityFactory.make<Entity>();
        entity->m_position = sf::Vector2f(i*100, 0);
        m_entities.emplace_back(std::move(entity));
    }
    std::unique_ptr<Ship> ship = entityFactory.make<Ship>();
    ship->m_position = sf::Vector2f(1000, 200);
    m_ship = ship.get();
    m_entities.emplace_back(std::move(ship));
}

void Game::moveForward()
{
    // Entity* entity = getEntity(1);
    if (m_ship) {
        m_ship->m_velocity = sf::Vector2f(0, 5);
    }
};

Entity* Game::getEntity(unsigned short id)
{
    for (auto& it : m_entities) {
        if (it->m_id == id) {
            return it.get();
        }
    }
    std::cout << "Entity " << id << " not found" << std::endl;
    return NULL;
};

void Game::stopMovingForward()
{
    for (auto& it : m_entities) {
        it->m_velocity = sf::Vector2f(0, 0);
    }
};

void Game::enactInputs(std::unique_ptr<Inputs> inputs)
{
    
    for (auto const& it : m_inputPressedFunctions) {
        if (inputs->isKeyPressed(it.first)) {
            it.second();
        }
    }
    for (auto const& it : m_inputReleasedFunctions) {
        if (inputs->isKeyReleased(it.first)) {
            it.second();
        }
    }
    for (auto const& it : m_inputDownFunctions) {
        if (inputs->isKeyDown(it.first)) {
            it.second();
        }
    }
}

void Game::run()
{
    for (auto& it : m_entities) {
        it->update();
    }
};

void Game::draw(sf::RenderWindow &window)
{
    for (auto& it : m_entities) {
        it->draw(window);
    }
};

void Game::setState(GameState& gameState)
{
    std::cout << gameState.DebugString();
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
};

GameState Game::getState()
{
    GameState gameState;
    for (auto& it : m_entities) {
        auto entityState = it->getState();
        EntityState* newEntityState = gameState.add_entities();
        newEntityState->CopyFrom(entityState);
    }
    return gameState;
};
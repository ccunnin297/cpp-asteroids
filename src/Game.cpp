#include "Game.h"

#include <iostream>

Game::Game()
{
    m_inputPressedFunctions = {
        {InputKey::Forward, std::bind(&Game::moveForward, this)},
        {InputKey::Back, std::bind(&Game::moveBackward, this)},
        {InputKey::Left, std::bind(&Game::turnLeft, this)},
        {InputKey::Right, std::bind(&Game::turnRight, this)}
    };
    m_inputReleasedFunctions = {
        {InputKey::Forward, std::bind(&Game::stopMovingForward, this)},
        {InputKey::Back, std::bind(&Game::stopMovingBackward, this)},
        {InputKey::Left, std::bind(&Game::stopTurningLeft, this)},
        {InputKey::Right, std::bind(&Game::stopTurningRight, this)}
    };
    m_entityFactory = std::make_unique<EntityFactory>();
};

void Game::addEntities()
{
    for (int i = 0; i < 5; ++i) {
        std::unique_ptr<Entity> entity = m_entityFactory->make<Entity>();
        entity->m_position = sf::Vector2f(i*100, 0);
        m_entities.emplace_back(std::move(entity));
    }
    std::unique_ptr<Ship> ship = m_entityFactory->make<Ship>();
    ship->m_position = sf::Vector2f(1000, 200);
    m_shipId = ship->m_id;
    m_entities.emplace_back(std::move(ship));
}

void Game::moveForward()
{
    auto ship = getEntity(m_shipId);
    ship->m_forward = true;
};

void Game::stopMovingForward()
{
    auto ship = getEntity(m_shipId);
    ship->m_forward = false;
};

void Game::moveBackward()
{
    auto ship = getEntity(m_shipId);
    ship->m_backward = true;
};

void Game::stopMovingBackward()
{
    auto ship = getEntity(m_shipId);
    ship->m_backward = false;
};

void Game::turnLeft()
{
    auto ship = getEntity(m_shipId);
    ship->m_turnLeft = true;
};

void Game::stopTurningLeft()
{
    auto ship = getEntity(m_shipId);
    ship->m_turnLeft = false;
};

void Game::turnRight()
{
    auto ship = getEntity(m_shipId);
    ship->m_turnRight = true;
};

void Game::stopTurningRight()
{
    auto ship = getEntity(m_shipId);
    ship->m_turnRight = false;
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
            auto newEntity = m_entityFactory->makeFromState(entStateIt);
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
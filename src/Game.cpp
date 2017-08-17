#include "Game.h"

#include "GameValues.h"
#include "utils.h"

#include <iostream>

Game::Game()
{
    m_inputPressedFunctions = {
        {InputKey::Forward, std::bind(&Game::moveForward, this)},
        {InputKey::Back, std::bind(&Game::moveBackward, this)},
        {InputKey::Left, std::bind(&Game::turnLeft, this)},
        {InputKey::Right, std::bind(&Game::turnRight, this)},
        {InputKey::Shoot, std::bind(&Game::shoot, this)}
    };
    m_inputReleasedFunctions = {
        {InputKey::Forward, std::bind(&Game::stopMovingForward, this)},
        {InputKey::Back, std::bind(&Game::stopMovingBackward, this)},
        {InputKey::Left, std::bind(&Game::stopTurningLeft, this)},
        {InputKey::Right, std::bind(&Game::stopTurningRight, this)},
        {InputKey::Shoot, std::bind(&Game::stopShooting, this)}
    };
    m_entityFactory = std::make_unique<EntityFactory>();
};

void Game::init()
{
    addShip();
    addAsteroids();
}

void Game::addAsteroids()
{
    for (int i = 0; i < NUM_ASTEROID_SPAWN; ++i) {
        std::unique_ptr<Asteroid> asteroid = m_entityFactory->make<Asteroid>();

        auto randomPosition = sf::Vector2f(randf(0, GAME_BOUNDS_X), randf(0, GAME_BOUNDS_Y));
        asteroid->setPosition(randomPosition);

        auto randomVelocity = randf(ASTEROID_MIN_VELOCITY, ASTEROID_MAX_VELOCITY);
        asteroid->setVelocity(randomVelocity);

        auto randomRotation = randi(0, 360);
        asteroid->setRotation(randomRotation);
        
        m_entities.emplace_back(std::move(asteroid));
    }
};

//TODO: combine entityFactory make and emplace_back with a lambda for simple constructor function
void Game::addShip()
{
    std::unique_ptr<Ship> ship = m_entityFactory->make<Ship>();
    ship->setPosition(sf::Vector2f(1000, 200));
    m_shipId = ship->getId();
    m_entities.emplace_back(std::move(ship));
};

void Game::moveForward()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setMoveForward(true);
    }
};

void Game::stopMovingForward()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setMoveForward(false);
    }
};

void Game::moveBackward()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setMoveBackward(true);
    }
};

void Game::stopMovingBackward()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setMoveBackward(false);
    }
};

void Game::turnLeft()
{
    Ship* ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setTurnLeft(true);
    }
};

void Game::stopTurningLeft()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setTurnLeft(false);
    }
};

void Game::turnRight()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setTurnRight(true);
    }
};

void Game::stopTurningRight()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        ship->setTurnRight(false);
    }
};

void Game::shoot()
{
    auto ship = (Ship*)getEntity(m_shipId);
    if (ship) {
        auto bullet = m_entityFactory->make<Bullet>();
        ship->shoot(bullet.get());
        m_entities.emplace_back(std::move(bullet));
    }
};

void Game::stopShooting()
{

};

Entity* Game::getEntity(unsigned short id)
{
    for (auto& it : m_entities) {
        if (it->getId() == id) {
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
    checkCollisions();
};

void Game::cleanup()
{
    cleanupEntities();
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
                return entity.get()->getId() == id;
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

void Game::checkCollisions()
{
    for (auto itA = m_entities.begin(); itA != m_entities.end(); ++itA) {
        for (auto itB = std::next(itA); itB != m_entities.end(); ++itB) {
            auto entityA = (*itA).get();
            auto entityB = (*itB).get();
            if (entityA->collidesWith(entityB)) {
                entityA->hasCollidedWith(entityB);
                entityB->hasCollidedWith(entityA);
            }
        }
    }
};

void Game::cleanupEntities()
{   
    for (auto it = findEntityToDestroy(); it != m_entities.end(); it = findEntityToDestroy()) {
        m_entities.erase(std::remove(m_entities.begin(), m_entities.end(), *it));
        std::move(it);
    }
};

std::vector<std::unique_ptr<Entity>>::iterator Game::findEntityToDestroy()
{
    return find_if(m_entities.begin(), m_entities.end(), 
        [&](auto& entity) {
            return entity->shouldDestroy();
        });
};
#include "Game.h"

#include "GameValues.h"
#include "utils.h"

#include "Logger.h"

Game::Game()
{
    m_phase = GameReady;

    m_inputPressedFunctions = {
        { GameReady, {
            {MenuAction, &Game::start}
        }},
        { GameRunning, {
            {Forward, &Game::moveForward},
            {Back, &Game::moveBackward},
            {Left, &Game::turnLeft},
            {Right, &Game::turnRight},
            {Shoot, &Game::shoot}
        }},
        { GameOver, {
            {MenuAction, &Game::start}
        }}
    };

    m_inputReleasedFunctions = {
        { GameRunning, {
            {Forward, &Game::stopMovingForward},
            {Back, &Game::stopMovingBackward},
            {Left, &Game::stopTurningLeft},
            {Right, &Game::stopTurningRight}
        }}
    };
    m_entityFactory = std::make_unique<EntityFactory>();
};

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
ID Game::addShip(int shipNumber)
{
    std::unique_ptr<Ship> ship = m_entityFactory->make<Ship>();
    ship->setShipType(static_cast<ShipType>(shipNumber));
    ship->setPosition(sf::Vector2f(1000, 200));
    ID shipId = ship->getId();
    m_entities.emplace_back(std::move(ship));

    return shipId;
};

void Game::moveForward(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setMoveForward(true);
    }
};

void Game::stopMovingForward(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setMoveForward(false);
    }
};

void Game::moveBackward(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setMoveBackward(true);
    }
};

void Game::stopMovingBackward(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setMoveBackward(false);
    }
};

void Game::turnLeft(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setTurnLeft(true);
    }
};

void Game::stopTurningLeft(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setTurnLeft(false);
    }
};

void Game::turnRight(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setTurnRight(true);
    }
};

void Game::stopTurningRight(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        ship->setTurnRight(false);
    }
};

void Game::shoot(Player* player)
{
    auto ship = (Ship*)getEntity(player->getShipId());
    if (ship) {
        auto bullet = m_entityFactory->make<Bullet>();
        ship->shoot(bullet.get());
        m_entities.emplace_back(std::move(bullet));
    }
};

void Game::start(Player* player)
{
    clearEntities();
    addPlayerShips();
    addAsteroids();
    m_phase = GameRunning;
};

void Game::clearEntities()
{
    for (auto& it : m_entities) {
        it->destroy();
    }
};

void Game::addPlayerShips()
{
    int playerCount = 0;
    for (auto& player : m_players) {
        ID shipId = addShip(playerCount);
        player->setShipId(shipId);
        playerCount++;
    }
};

Entity* Game::getEntity(ID id)
{
    for (const auto& it : m_entities) {
        if (it->getId() == id) {
            return it.get();
        }
    }
    Logger::log("Entity " + std::to_string(id) + " not found");
    return NULL;
};

void Game::enactInputs(Player* player)
{
    if(m_inputPressedFunctions.count(m_phase) != 0) {
        auto pressedFuncs = m_inputPressedFunctions.at(m_phase);
        for (auto const& it : pressedFuncs) {
            if (player->getInputs()->isKeyPressed(it.first)) {
                (this->*(it.second))(player);
            }
        }
    }
    
    if(m_inputReleasedFunctions.count(m_phase) != 0) {
        auto releasedFuncs = m_inputReleasedFunctions.at(m_phase);
        for (auto const& it : releasedFuncs) {
            if (player->getInputs()->isKeyReleased(it.first)) {
                (this->*(it.second))(player);
            }
        }
    }
}

void Game::addPlayer(std::shared_ptr<Player> player)
{
    m_players.emplace_back(player);
};

void Game::run(double deltas)
{
    for (auto& player : m_players) {
        //TODO: tidy this up
        if (player->newInputs()) {
            player->setNewInputs(false);
            enactInputs(player.get());
        }
    }
    for (auto& entity : m_entities) {
        entity->update(deltas);
    }
    checkCollisions();
};

void Game::cleanup()
{
    checkGameOver();
    cleanupEntities();
};

void Game::checkGameOver()
{
    if (m_phase == GameRunning) {
        int shipCount = m_players.size();
        for (auto& player : m_players) {
            auto ship = getEntity(player->getShipId());
            if (!ship) {
                shipCount--;
            }
        }
        if (shipCount == 0) {
            m_phase = GameOver;
        }   
    }
};

void Game::draw(sf::RenderWindow &window)
{
    for (const auto& it : m_entities) {
        it->draw(window);
    }
};

void Game::setState(GameState& gameState)
{
    auto entityStates = gameState.entities();
    for (const auto& entStateIt : entityStates) {
        ID id = entStateIt.id();

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
        std::move(*it);
    }
};

std::vector<std::unique_ptr<Entity>>::iterator Game::findEntityToDestroy()
{
    return find_if(m_entities.begin(), m_entities.end(), 
        [](const auto& entity) {
            return entity->shouldDestroy();
        });
};

void Game::removePlayer(std::shared_ptr<Player> player)
{
    auto ship = getEntity(player->getShipId());
    if (ship) {
        ship->destroy();
    }
    m_players.erase(std::remove(m_players.begin(), m_players.end(), player));
};
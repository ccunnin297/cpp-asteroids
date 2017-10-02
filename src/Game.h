#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "GameState.pb.h"
#include "Inputs.h"
#include "EntityFactory.h"
#include "Player.h"

#include <memory>

enum GamePhase {
    GameReady,
    GameRunning,
    GameOver
};

class Game
{
    public:
        Game();

        void addAsteroids();
        void run(double deltas);
        void draw(sf::RenderWindow &window);
        void cleanup();

        void setState(GameState& gameState);
        GameState getState();
        void enactInputs(Player* player);
        void addPlayer(std::shared_ptr<Player> player);
        void removePlayer(std::shared_ptr<Player> player);
    private:
        void moveForward(Player* player);
        void moveBackward(Player* player);
        void stopMovingForward(Player* player);
        void stopMovingBackward(Player* player);
        void turnLeft(Player* player);
        void stopTurningLeft(Player* player);
        void turnRight(Player* player);
        void stopTurningRight(Player* player);
        void shoot(Player* player);
        void start(Player* player);

        void clearEntities();
        ID addShip(int shipNumber);
        void addPlayerShips();

        Entity* getEntity(ID id);
        std::vector<std::unique_ptr<Entity>>::iterator findEntityToDestroy();

        void checkCollisions();
        void cleanupEntities();
        void checkGameOver();

        GamePhase m_phase;

        int m_numAsteroids;

        std::unique_ptr<EntityFactory> m_entityFactory;
        std::vector<std::unique_ptr<Entity>> m_entities;
        std::vector<std::shared_ptr<Player>> m_players;

        typedef void (Game::*ShipFunction)(Player*);
        
        std::map<GamePhase, std::map<InputKey, ShipFunction>> m_inputPressedFunctions;
        std::map<GamePhase, std::map<InputKey, ShipFunction>> m_inputReleasedFunctions;
};
#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "GameState.pb.h"
#include "Inputs.h"
#include "EntityFactory.h"

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

        void run();
        void draw(sf::RenderWindow &window);
        void cleanup();

        void setState(GameState& gameState);
        GameState getState();
        void enactInputs(std::unique_ptr<Inputs> inputs);
    private:
        void moveForward();
        void moveBackward();
        void stopMovingForward();
        void stopMovingBackward();
        void turnLeft();
        void stopTurningLeft();
        void turnRight();
        void stopTurningRight();
        void shoot();
        void start();

        void clearEntities();
        void addShip();
        void addAsteroids();

        Entity* getEntity(unsigned short id);
        std::vector<std::unique_ptr<Entity>>::iterator findEntityToDestroy();

        void checkCollisions();
        void cleanupEntities();
        void checkGameOver();

        unsigned short m_shipId;
        GamePhase m_phase;

        std::unique_ptr<EntityFactory> m_entityFactory;
        std::vector<std::unique_ptr<Entity>> m_entities;

        std::map<GamePhase, std::map<InputKey, std::function<void()>>> m_inputPressedFunctions;
        std::map<GamePhase, std::map<InputKey, std::function<void()>>> m_inputReleasedFunctions;
};
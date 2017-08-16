#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "GameState.pb.h"
#include "Inputs.h"
#include "EntityFactory.h"

#include <memory>

class Game
{
    public:
        Game();

        void addEntities();
        void run();
        void draw(sf::RenderWindow &window);

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
        void stopShooting();

        Entity* getEntity(unsigned short id);

        void checkCollisions();

        unsigned short m_shipId;

        std::unique_ptr<EntityFactory> m_entityFactory;
        std::vector<std::unique_ptr<Entity>> m_entities;
        std::map<InputKey, std::function<void()>> m_inputPressedFunctions;
        std::map<InputKey, std::function<void()>> m_inputReleasedFunctions;
};
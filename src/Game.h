#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Ship.h"
#include "GameState.pb.h"
#include "Inputs.h"

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
        void stopMovingForward();
        Entity* getEntity(unsigned short id);

        Ship* m_ship;

        std::vector<std::unique_ptr<Entity>> m_entities;
        std::map<InputKey, std::function<void()>> m_inputPressedFunctions;
        std::map<InputKey, std::function<void()>> m_inputReleasedFunctions;
        std::map<InputKey, std::function<void()>> m_inputDownFunctions;
};
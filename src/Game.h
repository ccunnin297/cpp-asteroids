#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
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
        void setInputState(u_int32_t inputState);

        GameState getState();
    private:
        void enactInputs();

        void moveForward();

        std::unique_ptr<Inputs> m_inputs;
        std::vector<std::unique_ptr<Entity>> m_entities;
        std::map<InputKey, std::function<void()>> m_inputFunctions;
};
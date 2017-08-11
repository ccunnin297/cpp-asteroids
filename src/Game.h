#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "GameState.pb.h"

#include <memory>

class Game
{
    public:
        Game();

        void addEntities();
        void run();
        void draw(sf::RenderWindow &window);

        std::unique_ptr<GameState> getState();
        void setState(GameState& gameState);        
    private:                
        std::vector<std::unique_ptr<Entity>> m_entities;
};
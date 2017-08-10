#pragma once

#include <SFML/Graphics.hpp>
#include <json.hpp>

#include "Entity.h"

class Game
{
    public:
        Game();

        void addEntities();
        void run();
        void draw(sf::RenderWindow &window);

        nlohmann::json getState();
        void setState(nlohmann::json jsonState);        
    private:                
        std::vector<std::unique_ptr<Entity>> m_entities;
};
#pragma once

#include <SFML/Graphics.hpp>
#include <json.hpp>

class Entity
{
    public:
        Entity(unsigned short id);
        Entity(nlohmann::json jsonState);
        nlohmann::json getState();
        void setState(nlohmann::json jsonState);

        unsigned short m_id;
        sf::Vector2f m_position;
    private:
};
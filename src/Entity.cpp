#include "Entity.h"

Entity::Entity(unsigned short id)
{
    m_id = id;
};

Entity::Entity(nlohmann::json jsonState)
{
    m_id = jsonState["id"];
    setState(jsonState);
}

nlohmann::json Entity::getState()
{
    return {
        {"id", m_id},
        {"position", {{"x", m_position.x}, {"y", m_position.y}}}
    };
};

void Entity::setState(nlohmann::json jsonState)
{
    m_position = sf::Vector2f(jsonState["position"]["x"], jsonState["position"]["y"]);
}
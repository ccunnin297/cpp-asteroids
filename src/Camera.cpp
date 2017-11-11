#include "Camera.h"

#include "GameValues.h"

void Camera::centerOnEntity(const Entity& entity)
{
    m_position = sf::Vector2f(entity.getPosition().x - WINDOW_BOUNDS_X / 2, entity.getPosition().y - WINDOW_BOUNDS_Y / 2);
};

//TODO: make this const entity
void Camera::draw(Entity& entity, sf::RenderWindow& window) const
{
    sf::View view(sf::Vector2f(m_position), sf::Vector2f(WINDOW_BOUNDS_X, WINDOW_BOUNDS_Y));
    window.setView(view);
    entity.draw(window);
};
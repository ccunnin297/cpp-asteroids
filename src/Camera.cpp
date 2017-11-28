#include "Camera.h"

#include "GameValues.h"

void Camera::centerOnEntity(const Entity& entity)
{
    m_position = sf::Vector2f(entity.getPosition().x, entity.getPosition().y);
};

sf::View Camera::getView()
{
    return sf::View(sf::Vector2f(m_position), sf::Vector2f(WINDOW_BOUNDS_X, WINDOW_BOUNDS_Y));
};
#include "ClientGame.h"

ClientGame::ClientGame()
{
    
};

void ClientGame::draw(sf::RenderWindow &window)
{
    for (auto it = m_entities.begin(); it != m_entities.end(); ++it) {
        sf::CircleShape circle(50);
        circle.setPosition((*it)->m_position);
        circle.setFillColor(sf::Color(100, 250, 50));
        window.draw(circle);
    }
};
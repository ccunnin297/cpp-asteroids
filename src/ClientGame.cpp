#include "ClientGame.h"

#include "GameValues.h"

ClientGame::ClientGame() : Game()
{
    m_player = std::make_unique<Player>();
};

void ClientGame::draw(Camera& camera, sf::RenderWindow &window)
{
    //Set up background
    sf::RectangleShape backgroundRectangle(sf::Vector2f(GAME_BOUNDS_X, GAME_BOUNDS_Y));
    backgroundRectangle.setPosition(0, 0);
    backgroundRectangle.setFillColor(sf::Color::Black);

    //Setup camera
    auto ship = getEntity(m_player->getShipId());
    if (ship) {
        camera.centerOnEntity(*ship);
    }

    //Get camera view
    sf::View cameraView = camera.getView();
    window.setView(cameraView);
    
    window.draw(backgroundRectangle);
    for (const auto& it : m_entities) {
        it->draw(window);
    }
    
    //Set up minimap view
    sf::View minimapView(sf::FloatRect(0, 0, GAME_BOUNDS_X, GAME_BOUNDS_Y));
    minimapView.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
    window.setView(minimapView);

    backgroundRectangle.setFillColor(sf::Color(54, 54, 54));
    window.draw(backgroundRectangle);
    for (const auto& it : m_entities) {
        it->draw(window);
    }
    
    
};
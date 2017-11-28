#include "ClientGame.h"

ClientGame::ClientGame() : Game()
{
    m_player = std::make_unique<Player>();
};

void ClientGame::draw(Camera& camera, sf::RenderWindow &window)
{
    auto ship = getEntity(m_player->getShipId());
    // auto ship = getFirstPlayerShip();
    if (ship) {
        camera.centerOnEntity(*ship);
    }
    for (const auto& it : m_entities) {
        camera.draw(*it, window);
    }
};
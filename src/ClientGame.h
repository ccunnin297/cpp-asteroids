#pragma once

#include "Game.h"

#include "Player.h"

class ClientGame : public Game
{
    public:
        ClientGame();

        void draw(Camera& camera, sf::RenderWindow &window);
        
        std::unique_ptr<Player> m_player;
    private:
};
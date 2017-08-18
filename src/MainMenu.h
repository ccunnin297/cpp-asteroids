#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "Inputs.h"

class Client;

class MainMenu
{
    public:
        MainMenu(Client* client);

        void hostGame();
        void connectToGame(sf::IpAddress address);

        void acceptInputs(Inputs* inputs);
        void draw(sf::RenderWindow &window);
        void run();
        void reset();
    private:
        Client* m_client;

        std::map<InputKey, std::function<void()>> m_inputPressedFunctions;
        std::map<InputKey, std::function<void()>> m_inputReleasedFunctions;
};
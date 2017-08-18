#include "MainMenu.h"

#include "GameValues.h"

#include "Client.h"

#include <iostream>

MainMenu::MainMenu(Client *client)
{
    m_client = client;

    m_inputPressedFunctions = {
        {
            {One, std::bind(&MainMenu::hostGame, this)}
        },
    };
};

void MainMenu::hostGame()
{
    m_client->hostGame();
};

void MainMenu::connectToGame(sf::IpAddress address)
{
    m_client->connectToGame(address);
};

void MainMenu::run()
{
    
};

void MainMenu::acceptInputs(Inputs* inputs)
{
    for (auto const& it : m_inputPressedFunctions) {
        if (inputs->isKeyPressed(it.first)) {
            it.second();
        }
    }
    
    for (auto const& it : m_inputReleasedFunctions) {
        if (inputs->isKeyReleased(it.first)) {
            it.second();
        }
    }
};

void MainMenu::draw(sf::RenderWindow &window)
{
    auto text1 = sf::Text();
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/BebasNeue/BebasNeue.otf")) {
        std::cout << "Error loading font from file" << std::endl;
        return;
    }
    text1.setFont(font);
    text1.setString("Press 1 to host");
    text1.setPosition(sf::Vector2f(GAME_BOUNDS_X / 2.0f, GAME_BOUNDS_Y / 2.0f));
    text1.setFillColor(sf::Color::White);
    text1.setCharacterSize(24);
    window.draw(text1);
};

void MainMenu::reset()
{

};
#pragma once

#include <SFML/Window.hpp>

#include <map>

class Inputs
{
    public:
        Inputs();

        void update();
    private:
        const std::map<sf::Keyboard::Key, uint32_t> m_keyMapping = {
            {sf::Keyboard::Down, 0b1},
            {sf::Keyboard::Up, 0b10},
            {sf::Keyboard::Left, 0b100}
        };
        uint32_t m_keyState;
};
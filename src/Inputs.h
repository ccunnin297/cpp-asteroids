#pragma once

#include <SFML/Window.hpp>

#include <map>

enum InputKey {
    Forward=        1<<1,
    Back=           1<<2,
    Left=           1<<3,
    Right=          1<<4
};

class Inputs
{
    public:
        Inputs();

        void setState(uint32_t keyState);
        void update();
        bool isKeyPressed(InputKey key);
    private:
        const std::map<InputKey, sf::Keyboard::Key> m_keyMapping = {
            {InputKey::Forward, sf::Keyboard::Up},
            {InputKey::Back, sf::Keyboard::Down},
            {InputKey::Left, sf::Keyboard::Left},
            {InputKey::Right, sf::Keyboard::Right}
        };
        uint32_t m_state;
};
#pragma once

#include <SFML/Window.hpp>

#include <map>
#include <memory>

#include "InputState.pb.h"

enum InputKey {
    Forward=        1<<0,
    Back=           1<<1,
    Left=           1<<2,
    Right=          1<<3,
    Shoot=          1<<4,
    MenuAction=     1<<5,
    Exit=           1<<6,
    One=            1<<7
};

class Inputs
{
    public:
        Inputs();
        Inputs(InputState inputState);

        InputState getState();
        void setState(InputState inputState);
        void update(sf::Event event);
        bool isKeyPressed(InputKey key);
        bool isKeyReleased(InputKey key);
    private:
        const std::map<InputKey, sf::Keyboard::Key> m_keyMapping = {
            {InputKey::Forward, sf::Keyboard::Up},
            {InputKey::Back, sf::Keyboard::Down},
            {InputKey::Left, sf::Keyboard::Left},
            {InputKey::Right, sf::Keyboard::Right},
            {InputKey::Shoot, sf::Keyboard::Space},
            {InputKey::MenuAction, sf::Keyboard::Space},
            {InputKey::One, sf::Keyboard::Num1}
        };
        std::unique_ptr<InputState> m_state;
};
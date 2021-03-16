#ifndef ENGINE_HPP_INCLUDED
#define ENGINE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>
#include "Ball.hpp"
#include "BallTest.hpp"
#include "inline.h"
#include "ParticuleGenerator.hpp"
#include "Firework.hpp"

class Engine
{
    public:
        Engine();
        ~Engine();

        void run();
        void update(sf::Time deltaTime);
        void processEvents();
        void handleKeyInput(sf::Keyboard::Key key, bool isPressed);
        void handleMouseInput(sf::Mouse::Button mouse, bool isPressed);
        void render();

    public: // Normalement privé
        bool MouseL=false, MouseR=false, Echap=false, MouseRPressed = false;
        bool Left=false, Right=false, Up=false, Space=false, Down=false;
        bool SpacePressed=false, UpPressed=false, DownPressed=false, LeftPressed=false, RightPressed=false;
        sf::RenderWindow m_window;
        sf::Time TimePerFrame;
        sf::Font m_fontEditor;
        sf::Text m_textEditor;
        ParticuleGenerator generator;
        std::vector<Firework*> l_f;
};

#endif // ENGINE_HPP_INCLUDED
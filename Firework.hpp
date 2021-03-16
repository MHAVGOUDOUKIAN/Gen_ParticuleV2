#ifndef FIREWORK_HPP_INCLUDED
#define FIREWORK_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "Particule.hpp"
#include "ParticuleGenerator.hpp"

class Firework
{
    public:
        Firework(const float X, const float Y);
        ~Firework();

        void update(const sf::Time& deltaTime);
        void draw(sf::RenderWindow& window) { genPar.draw(window);}

    public:
        bool isDead = false;
        sf::Vector2f vit;
        ParticuleGenerator genPar;
        float lifeTime, lifeTimeMax;
};

#endif // FIREWORK_HPP_INCLUDED

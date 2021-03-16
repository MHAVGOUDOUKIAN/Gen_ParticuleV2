#include "Firework.hpp"
#include "inline.h"

Firework::Firework(const float X, const float Y) : genPar(X,Y), vit(sf::Vector2f(0,randomf(-40,-30))), 
lifeTime(0), lifeTimeMax(3.f)
{
    genPar.setTypeParticule(3);
    genPar.setParticulePerSecond(300.f);
    genPar.setLifeTimeParticule(0.0f);
    genPar.start();
}

Firework::~Firework() {}

void Firework::update(const sf::Time& deltaTime)
{
    lifeTime += deltaTime.asSeconds();

    if(lifeTime > lifeTimeMax) { isDead = true; }

    if(vit.y <= 0)
    {
        genPar.setPosition(genPar.getPosition().x + vit.x, genPar.getPosition().y + vit.y);
        vit.y+= 1 ;
        if(vit.y + 1 >=0)
        {
            genPar.stop();
            genPar.setLifeTimeParticule(0.7f);
            genPar.setTypeParticule(5);
            for(int i=0; i<400; i++)
            {
                genPar.add();
            }
        }
    }

    genPar.update(deltaTime);

}
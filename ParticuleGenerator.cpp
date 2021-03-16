#include "ParticuleGenerator.hpp"
#include "Particule.hpp"
#include <iostream>

ParticuleGenerator::ParticuleGenerator() : pos(sf::Vector2f(0,0)), typeParticule(0), working(false), EnableDuration(false), duration(2.f),
lifeTime(0), particulePerSecond(300), timeLastParticuleAdded(0), lifeTimeParticule(0.5f) {}

ParticuleGenerator::ParticuleGenerator(const float X, const float Y): pos(sf::Vector2f(X,Y)), typeParticule(0), working(false), EnableDuration(false),
duration(2.f), lifeTime(0), particulePerSecond(300), timeLastParticuleAdded(0), lifeTimeParticule(0.5f) {}
void ParticuleGenerator::update(sf::Time deltaTime)
{
    lifeTime += deltaTime.asSeconds();

    if(isWorking()) { emit(deltaTime); }

    if(EnableDuration && lifeTime > duration) {
        stop();
        lifeTime = 0;
    }

    for(int i=0; i < int(lParticules.size()); i++) {
        if(!lParticules[i]->isDead()) {
            lParticules[i]->update(deltaTime);
        }
        else {
            delete lParticules[i];
            lParticules.erase(lParticules.begin()+i);
            i--;
        }
    }
}

void ParticuleGenerator::add(const float X, const float Y)
{
    if(typeParticule == 0) {setParticulePerSecond(1000); lParticules.push_back(new Particule_Ball(sf::Mouse::getPosition().x + this->pos.x ,sf::Mouse::getPosition().y + this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 1) {setParticulePerSecond(2000); lParticules.push_back(new Particule_Snow(sf::Mouse::getPosition().x + this->pos.x ,sf::Mouse::getPosition().y + this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 2) {setParticulePerSecond(5000); lParticules.push_back(new Particule_Dot(sf::Mouse::getPosition().x + this->pos.x ,sf::Mouse::getPosition().y + this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 3) {setParticulePerSecond(1000); lParticules.push_back(new Particule_Fire(sf::Mouse::getPosition().x + this->pos.x ,sf::Mouse::getPosition().y + this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 4) {setParticulePerSecond(600); lParticules.push_back(new Particule_Trail(sf::Mouse::getPosition().x + this->pos.x ,sf::Mouse::getPosition().y + this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 5) {setParticulePerSecond(600); lParticules.push_back(new Particule_Dot_Fall(sf::Mouse::getPosition().x + this->pos.x ,sf::Mouse::getPosition().y + this->pos.y, lifeTimeParticule));}
    lParticules[lParticules.size()-1]->launch(lParticules[lParticules.size()-1]->getPosition().x, lParticules[lParticules.size()-1]->getPosition().y, randomf(-700,700), randomf(-1000,1000));
}

void ParticuleGenerator::add()
{
    if(typeParticule == 0) {setParticulePerSecond(1000); lParticules.push_back(new Particule_Ball(this->pos.x ,this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 1) {setParticulePerSecond(2000); lParticules.push_back(new Particule_Snow(this->pos.x ,this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 2) {setParticulePerSecond(5000); lParticules.push_back(new Particule_Dot(this->pos.x ,this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 3) {setParticulePerSecond(1000); lParticules.push_back(new Particule_Fire(this->pos.x ,this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 4) {setParticulePerSecond(600); lParticules.push_back(new Particule_Trail(this->pos.x ,this->pos.y, lifeTimeParticule));}
    else if(typeParticule == 5) {setParticulePerSecond(600); lParticules.push_back(new Particule_Dot_Fall(this->pos.x ,this->pos.y, lifeTimeParticule));}
    lParticules[lParticules.size()-1]->launch(lParticules[lParticules.size()-1]->getPosition().x, lParticules[lParticules.size()-1]->getPosition().y, randomf(-700,700), randomf(-1000,1000));
}

void ParticuleGenerator::draw(sf::RenderWindow& window)
{
    for(int i=0; i < int(lParticules.size()) ; i++) {
        lParticules[i]->draw(window);
    }
}

void ParticuleGenerator::emit(sf::Time deltaTime)
{
    timeLastParticuleAdded = timeLastParticuleAdded + deltaTime.asSeconds() * (particulePerSecond); // On calcule le temps qu'il s'est écoulé depuis la dernière update et donc le nombre d'image qui doit être affichées pour respecter la cadence particulePerSecond
    if(timeLastParticuleAdded >= 1) // Si on doit ajouter au moins une particule;;
    {
        for(int i=0; i < int(timeLastParticuleAdded); i++) // On ajoute le bon nombre de particules
        {
            add();
        }
        timeLastParticuleAdded -= int(timeLastParticuleAdded); // On retire le nombre de particules retirées du compteur
    }
}

void ParticuleGenerator::start(void)
{
    if(!isWorking()) {
        working = true;
        lifeTime=0;
        timeLastParticuleAdded=0;
    }
}

void ParticuleGenerator::stop(void)
{
    if(isWorking()) {
        working = false;
        lifeTime=0;
        timeLastParticuleAdded=0;
    }
}

ParticuleGenerator::~ParticuleGenerator() {}

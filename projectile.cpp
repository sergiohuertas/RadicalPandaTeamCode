#include "projectile.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>



projectile::projectile(float newmspeed, int newdirection, bool newfriendly, int newdamage, float newangle, float x_player, float y_player) {
    mSpeed = newmspeed;
    direction = newdirection;
    friendly = newfriendly;
    damage = newdamage;
    angle = newangle;
    tx_flecha = new sf::Texture();
    if (!tx_flecha->loadFromFile("resources/arrow.png"))
    {
        std::cerr << "Error cargando la imagen archer_ss.png";
        exit(0);
    }
    
    sprite = new sf::Sprite(*tx_flecha);
    sprite->setOrigin(0, 2.5);
    sprite->setRotation((angle*360)/-(M_PI*2));
    sprite->setPosition(x_player, y_player);
}

projectile::~projectile(){
    delete tx_flecha;
    delete sprite;
}

void projectile::move(){
    /*if (direction == 1) // Up
    {
        rect.move(0, -mSpeed);
    }
    if (direction == 2) // Down
    {
        rect.move(0, mSpeed);
    }
    if (direction == 3) // Left
    {
        rect.move(-mSpeed, 0);
    }
    if (direction == 4) // Right
    {
        rect.move(mSpeed, 0);
    }*/
    sprite->move(mSpeed*cos(angle),-mSpeed*sin(angle));
}

void projectile::setDirection(int d){
    if (d == 1) // Up
    {
        direction=1;
    }
    if (d == 2) // Down
    {
        direction=2;
    }
    if (d == 3) // Left
    {
        direction=3;
    }
    if (d == 4) // Right
    {
        direction=4;
    }
}

void projectile::setPosition(int x, int y){
    sprite->setPosition(x, y);
}

void projectile::setAngle(int a){
    angle = a;
}

int projectile::getXPosition(){
    return sprite->getPosition().x;
}

int projectile::getYPosition(){
    return sprite->getPosition().y;
}

void projectile::draw(sf::RenderWindow &window){
    window.draw(*sprite);
}

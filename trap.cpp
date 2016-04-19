#include "trap.h"
#include <SFML/Graphics.hpp>
#include <iostream>

trap::trap() {
}

trap::trap(const trap& orig, int x, int y, int attack) {    
    playerX=x;
    playerY=y;
    trapAttack=attack*3;
    
    textrap=new sf::Texture;
    if (!textrap->loadFromFile("resources/trampa.png"))
    {
        std::cerr<<"Error cargando la imagen trampa.png";
        exit(0);
    }

    spritetrap=new sf::Sprite(*textrap);  
    spritetrap->setOrigin(20/2,20/2);
    spritetrap->setTextureRect(sf::IntRect(0, 0, 20, 20));
    spritetrap->setPosition(playerX, playerY);    
     
}

trap::~trap() {
    delete spritetrap;
    delete textrap;
}

void trap::doDamage(int e_speed){

    setHp(trapAttack);
    setSpeed(e_speed*0.5);         
    
}

void trap::drawTrap(sf::RenderWindow &window){
    window.draw(*spritetrap); 
}

int trap::getplayerX(){
    return playerX;
}

int trap::getplayerY(){
    return playerY;
}

int trap::getAttack(){
    return trapAttack;
}


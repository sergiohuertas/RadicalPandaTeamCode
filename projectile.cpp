// Aun falta por acabar
#include "projectile.h"

projectile::projectile() {
    rect.setSize(sf::Vector2f(25, 25));
    rect.setPosition(-50, -50);
    rect.setFillColor(sf::Color::Green);
}

void projectile::move(){
    if (direction == 1) // Up
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
    }
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
    rect.setPosition(x, y);
}

int projectile::getXPosition(){
    return rect.getPosition().x;
}

int projectile::getYPosition(){
    return rect.getPosition().y;
}

void projectile::draw(sf::RenderWindow &window){
    window.draw(rect);
}

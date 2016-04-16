// Aun sin acabar
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>

class projectile {
public:
    projectile();
    void move();
    void setDirection(int d);
    void setPosition(int x, int y);
    int getXPosition();
    int getYPosition();
    void draw(sf::RenderWindow &window);
private:
    int mSpeed=2;
    int direction=0; // 1 - up, 2 - down, 3 - left, 4 - right
    bool friendly=true; // False - Enemigo
    int damage=5;
    sf::RectangleShape rect; // Sprite
};

#endif

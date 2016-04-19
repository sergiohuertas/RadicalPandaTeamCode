#ifndef TRAP_H
#define TRAP_H
#include <SFML/Graphics.hpp>
#include <iostream>

class trap {
public:
    trap();
    trap(const trap& orig, int x, int y, int attack);
    virtual ~trap();    
    void doDamage(int e_speed);
    void drawTrap(sf::RenderWindow &window);
    int getplayerX();
    int getplayerY();
    int getAttack();        
    
private:    
    /*bool explosion;*/    
    int playerX;
    int playerY;
    int trapAttack;    
    sf::Texture *textrap;
    sf::Sprite *spritetrap;
    sf::Clock *slow;

};

#endif /* TRAP_H */


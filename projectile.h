// Aun esta sin acabar
#ifndef PROJECTILE_H
#define PROJECTILE_H
#include <SFML/Graphics.hpp>
class projectile {
public:
    projectile(float newmspeed, int newdirection, bool newfriendly, int newdamage, float newangle, float x_player, float y_player);
    //projectile(const projectile& orig);
    void move();
    virtual ~projectile();
    void setDirection(int d);
    void setPosition(int x, int y);
    void setAngle(int a);
    int getXPosition();
    int getYPosition();
    void draw(sf::RenderWindow &window);
private:
    float mSpeed;
    int direction; // 1 - up, 2 - down, 3 - left, 4 - right
    bool friendly; // False - Enemigo
    int damage;
    float angle;
    sf::Sprite *sprite;
    sf::Texture *tx_flecha;
    
    //sf::RectangleShape rect; // Sprite
};

#endif

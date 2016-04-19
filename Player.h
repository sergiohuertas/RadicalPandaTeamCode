/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: Rafael
 *
 * Created on 16 de abril de 2016, 17:19
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    Player(int x, int y);
    
    Player(const Player& orig);
    virtual ~Player();
    void act(sf::RenderWindow &w);
    int getHp();
    int getMaxHp();
    int getMana();
    int getMaxMana();
    int getLevel();
    int getXp();
    int getNextXp();
    int getAttack();
    int getArmor();
    int getPotions();
    int getMspd();
    void setPotions(int c);
    // Movement
    void getInput();
    void movement(sf::RenderWindow &window);
    int getFacing();
    /// Fighting
    // Skills
    bool castBasicAttack();
    bool castSpreadAttack();
    bool castDash();
    bool castTrap();
    bool castKickAttack();
    // Stats
    void levelUp();
    void gainXp(int x);
    void takeDamage(int d);
    // Other
    void die ();
    void draw(sf::RenderWindow &w);
    void spriteControl();
private:
    int state;
    enum states {Idle, Move, Shoot, Dash, Kick};  // [idle,move,shoot,dash,kick]
    //Stats
    int hp; //Herencia
    int maxhp; //Herencia
    int mana;
    int maxmana;
    int level;
    bool inmune; // Hittable = mesa de golpes
    // Progresion
    int xp;
    int xpnext;
    int skill_unlock [4];// = {3, 5, 9, 13}; // [abanico, dash, trampa, patada] ataque basico siempre disponible.
    int attack;
    int armor;
    int potions;
    // Movement
    int mspd;
    int xspd;
    int yspd;
    enum Direction { Down, Left, Right, Up }; 
    bool idle;
    sf::Window window;
    // Cooldowns
    int cooldowns[5];// = {1, 6, 6, 10, 8}; // [basico, abanico, dash, trampa, patada]
    sf::Clock basicAttackCD;
    sf::Clock spreadAttackCD;
    sf::Clock dashCD;
    sf::Clock trapCD;
    sf::Clock kickAttackCD;
    //Visual
    sf::Sprite spr;
    sf::Texture pTexture;
    sf::Clock animClock;
    sf::Clock global;
    sf::Clock dashClock;
    sf::Clock moveClock;
    sf::Vector2i source;
    sf::FloatRect hitBox;
};

#endif /* PLAYER_H */


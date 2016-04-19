/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: Rafael
 * 
 * Created on 16 de abril de 2016, 17:19
 */
#include <math.h> 
#include "Player.h"
#include <SFML/Graphics.hpp>

Player::Player(int x, int y) {
    hp = 100;
    maxhp = 100;
    mana = 100;
    maxmana = 100;
    level = 1;
    xp = 0;
    xpnext = 30;
    attack = 5;
    armor = 0;
    potions = 0;
    mspd = 3;
    source.x = 41;
    source.y = Down;
    if (!pTexture.loadFromFile("resources/archer_walk_ss.png")) {
        //std::cout << "Error al cargar resources/archer_walk_ss.png" <<std::endl;
    }
    spr.setTexture(pTexture);
    spr.setOrigin(41/2,59/2);
    spr.setPosition(x,y);
    skill_unlock[0]= 3;
    skill_unlock[1]= 5;
    skill_unlock[2]= 9;
    skill_unlock[3]= 13;
    cooldowns[0] = 1;
    cooldowns[1] = 6;
    cooldowns[2] = 6;
    cooldowns[3] = 10;
    cooldowns[4] = 8;
    Player::spriteControl();
}
Player::Player() {}
Player::~Player() {}
int Player::getHp(){
    return hp;
}
int Player::getMaxHp(){
    return maxhp;
}
int Player::getMana(){
    return mana;
}
int Player::getMaxMana(){
    return maxmana;
}
int Player::getLevel(){
    return level;
}
int Player::getXp(){
    return xp;
}
int Player::getNextXp(){
    return xpnext;
}
int Player::getAttack(){
    return attack;
}
int Player::getArmor(){
    return armor;
}
int Player::getPotions(){
    return potions;
}
//Herencia
int Player::getMspd(){
    return mspd;
}
void Player::act(sf::RenderWindow &w){
    Player::getInput();
    Player::movement(w);
    Player::spriteControl();
    Player::draw(w);
}
// Movement
void Player::getInput(){
    //Action input
    /*if (global.getElapsedTime().asSeconds() >= 1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            if (Player::castBasicAttack()) {
                state = Shoot;
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)){
            if (Player::castSpreadAttack()) {
                state = Shoot;
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            if (Player::castDash()) {
                state = Dash;
            }
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
            Player::castTrap();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            if (Player::castKickAttack()) {
                state = Kick;
            }
        }
    
    }*/
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
        Player::setPotions (-1);
    }
    //Movement input
    //if (state != Kick && state != Shoot) {

        xspd = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        yspd = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    //}
    
}
void Player::movement(sf::RenderWindow &window) {
    // No salirse del mapa por la izquierda
    if(spr.getPosition().x - mspd <= 0 + spr.getOrigin().x && xspd == -1) {
       xspd = 0; 
       if (yspd == 0) {
           idle = true;
       }
    }

    // No salirse del mapa por la derecha
    if(spr.getPosition().x + mspd >= window.getSize().x - spr.getOrigin().x && xspd == 1) {
       xspd = 0;
       if (yspd == 0) {
           idle = true;
       }
    }

    // No salirse del mapa por arriba
    if(spr.getPosition().y - mspd <= 0 + spr.getOrigin().y && yspd == -1) {
       yspd = 0;
       if (xspd == 0) {
           idle = true;
       }
    }

    // No salirse del mapa por abajo
    if(spr.getPosition().y + mspd >= window.getSize().y - spr.getOrigin().y && yspd == 1) {
       yspd = 0;  
       if (xspd == 0) {
           idle = true;
       }
    }

    // Moverse a la misma velocidad en diagonal que en vertical/horizontal
    
    if (xspd != 0 || yspd != 0) {
        state = Move;
    }
    if (xspd != 0 && yspd != 0) {
        xspd = xspd / sqrt(2);
        yspd = yspd / sqrt(2);
    }
    if (moveClock.getElapsedTime().asMilliseconds() > 1000/30) {
            spr.move(xspd *mspd,yspd * mspd);
            moveClock.restart();
        }
    //spr.move(xspd * mspd, yspd * mspd);
    hitBox = spr.getGlobalBounds();
}
/// Fighting
// Skills
bool Player::castBasicAttack(){
    if (basicAttackCD.getElapsedTime().asSeconds() > cooldowns[0]){
       // Projectile* p = new Projectile();
        basicAttackCD.restart();
    }
}
bool Player::castSpreadAttack(){
    if (level >= skill_unlock[0]) {
        if(mana > 20){
            if (dashCD.getElapsedTime().asSeconds() > cooldowns[1]){
                /*Projectile * p1 = new Projectile();
                Projectile * p2 = new Projectile();
                Projectile * p3 = new Projectile();
                Projectile * p4 = new Projectile();
                Projectile * p5 = new Projectile();*/
                mana -= 20;
                spreadAttackCD.restart();
            }
        }
    }
}
bool Player::castDash(){
    if (level >= skill_unlock[1]) {
        if(mana > 20){
            if (dashCD.getElapsedTime().asSeconds() > cooldowns[2]){
                dashClock.restart();
                
                mana -= 20;
                dashCD.restart();
            }
        }
    }
}
bool Player::castTrap(){
    if (level >= skill_unlock[2]) {
        if(mana > 20){
            if (trapCD.getElapsedTime().asSeconds() > cooldowns[3]){
               // Trap* tr = new Trap (spr.getPosition().x, spr.getPosition().y, attack,);
                mana -= 20;
                trapCD.restart();
            }
        }
    }
}
bool Player::castKickAttack() {
    if (level >= skill_unlock[3]) {
        if(mana > 15){
            if (kickAttackCD.getElapsedTime().asSeconds() > cooldowns[4]){
             //   Trap* tr = new Trap (spr.getPosition().x, spr.getPosition().y, attack,);
                mana -= 20;
                kickAttackCD.restart();
            }
        }
    }
}
// Stats
void Player::levelUp(){
    level += 1;
    hp += 20;
    maxhp += 20;
    mana += 10;
    maxmana += 10;
}
void Player::gainXp(int x) {
    xp += x;
    if (xp > xpnext) {
        xp -= xpnext;
        xpnext = xpnext + xpnext ^ (1/5);
        Player::levelUp();
    }
}
void Player::takeDamage(int d) {
    hp -= d;
    if (hp <= 0) {
        Player::die();
    }
}
void Player::die() {
    /*
     que hace
     */
}
// Other
void Player::draw(sf::RenderWindow &w) {
    w.draw(spr);
}
void Player::spriteControl(){
    // Controlar sprite
    if (yspd == -1 && (xspd == 0 || xspd == -1)) {
        source.y = Up;
        idle = false;
    }
    else if (yspd == 1 && (xspd == 0 || xspd == 1)) {
        source.y = Down;
        idle = false;
    }
    else if (xspd == 1 && (yspd == 0 || yspd == -1)) {
        source.y = Right;
        idle = false;
    }
    else if (xspd == -1 && (yspd == 0 || yspd == 1)) {
        source.y = Left;
        idle = false;
    } else {
        idle = true;
    }
    if (idle) {
        if (!pTexture.loadFromFile("resources/archer_idle_ss.png")) {
//            std::cout << "Error al cargar resources/archer_idle_ss.png" <<std::endl;
        }
        source.x = 0;
    } else {
       // if (state == Move) {
            if (!pTexture.loadFromFile("resources/archer_walk_ss.png")) {
           //     std::cout << "Error al cargar resources/archer_walk_ss.png" <<std::endl;
            }
       /* } else  if (state == Shoot) {
            if (!pTexture.loadFromFile("resources/archer_shoot_ss.png")) {
          //      std::cout << "Error al cargar resources/archer_walk_ss.png" <<std::endl;
            }
        } else if (state == Kick) {
            if (!pTexture.loadFromFile("resources/archer_kickk_ss.png")) {
            //    std::cout << "Error al cargar resources/archer_walk_ss.png" <<std::endl;
            }
        }*/
    }

    if (!idle && animClock.getElapsedTime().asMilliseconds() > 1000/10) {
        source.x++;
        animClock.restart();
    }
    if (source.x * 41 >= pTexture.getSize().x) {
        source.x = 0;
    }
    spr.setTextureRect(sf::IntRect(source.x * 41, source.y *59, 41, 59));
    hitBox = spr.getGlobalBounds();
}
int Player::getFacing () {
    int f;
    if (source.y == Right) {
        f = 0;
    } else if ( source.y == Up) {
        f = 1;
    } else if ( source.y == Left) {
        f = 2;
    } else {
        f = 3;
    }
    return f;
}
void Player::setPotions (int c){
    if(c == -1 && potions != 0 && hp != maxhp){
        hp += 30;
        if (hp > maxhp) {
            hp = maxhp;
        }
        potions --;
    } else {
        potions ++;
    }
}

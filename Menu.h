#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>

#define MAX_NUMBER_OF_ITEMS 4

class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
        void BuyItem(int n);
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font *font;
        sf::Sprite *sprite[];
        sf::Texture *armadura;
        sf::Texture *arma;
        sf::Texture *pocion;
        sf::Texture fondo;
    
        const sf::Texture *pBackground;
        sf::RectangleShape bg;
        
        // texto de menu
        sf::Text *textoComprarArmadura;
        sf::Text *textoComprarArma;
        sf::Text *textoComprarPociones;
        sf::Text *textoSalir;
        // Creamos el texto
        sf::Text *textoDinero;
        sf::Text *NumDinero;
        int dinero;
        sf::Text *textoPocion;
        sf::Text *NumPociones;
        int pociones;
        sf::Text *textoDanyo;
        sf::Text *NumDanyo;
        int danyo;
        sf::Text *textoDefensa;
        sf::Text *NumDefensa;
        int defensa;
        
        sf::Text *PrecioFotoDefensa;
        sf::Text *NumFotoDefensa;
        int fotoPrecioDefensa;
        int fotoNumDefensa;
        sf::Text *PrecioFotoDanyo;
        sf::Text *NumFotoDanyo;
        int fotoPrecioDanyo;
        int fotoNumDanyo;
        sf::Text *PrecioFotoPocion;
        sf::Text *NumFotoPocion;
        
        //SONIDO//
        float soundVolumeShop;
        sf::SoundBuffer *bufferShop;
        sf::Sound *soundShop;

        //////
      
};

#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/Audio.hpp>


class MenuPrincipal {
public:
    
    MenuPrincipal(float width, float height);
	~MenuPrincipal();
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    void SetPage(int n);
    void SelectOption(int n);
    bool HandleEvents(sf::RenderWindow &window);
    int GetPressedItem() { return selectedItemIndex; }
        
private:
    
    int page;//para saber en que pagina del menu estoy
    int selectedItemIndex;
    sf::Text *texnuevaPartida;
    sf::Text *texsalir;
    sf::Text *texopciones;
    sf::Text *texaboutUs;
    sf::Text *texsatras;
    
    sf::Texture *menuPrincipalFondo;
    sf::Texture *pBackground;
    sf::RectangleShape *bg;
    sf::Texture *menuAboutUsFondo;
    sf::Texture *menuOpcionesFondo;
    /*sf::Texture *texmenuPrincipal;
    sf::Texture *texmenuNuevaPartida;
    sf::Texture *texmenuNuevaPartidaPersonaje;
    sf::Texture *texmenuNuevaPartidaPersonaje2;
    sf::Texture *texmenuNuevaPartidaDificultad;
    sf::Texture *texmenuNuevaPartidaDificultad2;
    sf::Texture *texmenuNuevaPartidaJugar;
    sf::Texture *texmenuPausa;
    sf::Texture *texmenuPausaContinuar;
    sf::Texture *texmenuPausaVolver;
    sf::Texture *texmenuPausaTrucos; 
    sf::Texture *texmenuAboutUs; 
    sf::Texture *texmenuOpciones;
    sf::Texture *texmenuOpcionesMas;
    sf::Texture *texmenuOpcionesMenos;
    sf::Texture *texmenuOpcionesSilenciar;
    sf::Texture *texmenuTrucos; 
    sf::Texture *texborrar;
    sf::Texture *texatras;
    sf::Texture *texmouse;
    */
   /* std::string str;
    sf::Text *text;*/
    
    sf::Font *font;
   //SONIDO//
    float soundVolume;
    
    sf::SoundBuffer *buffer;
    sf::Sound *sound;
    
    //////
    
    
    
    
};


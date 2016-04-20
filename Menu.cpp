#include "Menu.h"
#include <iostream>
#include <sstream>
#include <string>
#include <SFML/Audio.hpp>


static inline std::string int2Str(int x)
{
    std::stringstream type;
    type << x;
    return type.str();
}

Menu::Menu(float width, float height)
{
        font = new sf::Font();
        
	if (!font->loadFromFile("resources/arial.ttf"))
	{
            std::cerr << "Error cargando la fuente arial.ttf";
            exit(0);
	}
        
        *sprite = new sf::Sprite[3];
        armadura = new sf::Texture();
        arma = new sf::Texture();
        pocion = new sf::Texture();
        
        
        bufferShop = new sf::SoundBuffer();
        soundShop = new sf::Sound();   
        
         if (!armadura->loadFromFile("resources/armadura.png"))
        {
            std::cerr << "Error cargando la imagen armadura.png";
            exit(0);
        }

        if (!arma->loadFromFile("resources/arma.png"))
        {
            std::cerr << "Error cargando la imagen arma.png";
            exit(0);
        }
        if (!pocion->loadFromFile("resources/pocion.png"))
        {
            std::cerr << "Error cargando la imagen pocion.png";
            exit(0);
        }
        //parte de fondo
        if (!fondo.loadFromFile("resources/fondo.png"))
        {
            std::cerr << "Error cargando la imagen fondo.png";
            exit(0);
        }
        //SONIDO//
        soundVolumeShop=100;
        if (!bufferShop->loadFromFile("resources/soundshop.ogg")){
            std::cerr << "Error cargando el audio soundshop.ogg";
            exit(0);
        }
        soundShop->setBuffer(*bufferShop);
        soundShop->setVolume(soundVolumeShop);
        soundShop->play();
        //////////////////////////////////////
        
        pBackground = &fondo;
        bg.setSize(sf::Vector2f(800,600));
        bg.setTexture(pBackground, true);
        /////////////////////////////////////
        //parte de textos
        textoDinero = new sf::Text();
        textoDinero->setFont(*font);
        textoDinero->setCharacterSize(20);
        textoDinero->setString("Dinero:");
        textoDinero->setPosition(5,5);
        NumDinero = new sf::Text();
        NumDinero->setFont(*font);
        NumDinero->setCharacterSize(20);
        NumDinero->setPosition(75,5);
        dinero=3000;
        
        textoPocion = new sf::Text();
        textoPocion->setFont(*font);
        textoPocion->setCharacterSize(20);
        textoPocion->setString("Pociones:");
        textoPocion->setPosition(130,5);
        NumPociones = new sf::Text();
        NumPociones->setFont(*font);
        NumPociones->setCharacterSize(20);
        NumPociones->setPosition(220,5);
        pociones=0;
        
        textoDanyo = new sf::Text();
        textoDanyo->setFont(*font);
        textoDanyo->setCharacterSize(20);
        textoDanyo->setString("Ataque:");
        textoDanyo->setPosition(240,5);
        NumDanyo = new sf::Text();
        NumDanyo->setFont(*font);
        NumDanyo->setCharacterSize(20);
        NumDanyo->setPosition(320,5);
        danyo=0;
        
        textoDefensa = new sf::Text();
        textoDefensa->setFont(*font);
        textoDefensa->setCharacterSize(20);
        textoDefensa->setString("Defensa:");
        textoDefensa->setPosition(350,5);
        NumDefensa = new sf::Text();
        NumDefensa->setFont(*font);
        NumDefensa->setCharacterSize(20);
        NumDefensa->setPosition(440,5);
        defensa=0;
        
        PrecioFotoDefensa = new sf::Text();
        PrecioFotoDefensa->setFont(*font);
        PrecioFotoDefensa->setColor(sf::Color::Black);
        PrecioFotoDefensa->setCharacterSize(20);
        PrecioFotoDefensa->setPosition(685,145);
        NumFotoDefensa = new sf::Text();
        NumFotoDefensa->setFont(*font);
        NumFotoDefensa->setColor(sf::Color::Black);
        NumFotoDefensa->setCharacterSize(20);
        NumFotoDefensa->setPosition(535,145);
        fotoPrecioDefensa=100;
        fotoNumDefensa=5;
        
        PrecioFotoDanyo = new sf::Text();
        PrecioFotoDanyo->setFont(*font);
        PrecioFotoDanyo->setColor(sf::Color::Black);
        PrecioFotoDanyo->setCharacterSize(20);
        PrecioFotoDanyo->setPosition(685,270);
        NumFotoDanyo = new sf::Text();
        NumFotoDanyo->setFont(*font);
        NumFotoDanyo->setColor(sf::Color::Black);
        NumFotoDanyo->setCharacterSize(20);
        NumFotoDanyo->setPosition(535,270);
        fotoPrecioDanyo=300;
        fotoNumDanyo=5;
        
        PrecioFotoPocion = new sf::Text();
        PrecioFotoPocion->setFont(*font);
        PrecioFotoPocion->setColor(sf::Color::Black);
        PrecioFotoPocion->setCharacterSize(20);
        PrecioFotoPocion->setString("50$");
        PrecioFotoPocion->setPosition(685,390);
        NumFotoPocion = new sf::Text();
        NumFotoPocion->setFont(*font);
        NumFotoPocion->setColor(sf::Color::Black);
        NumFotoPocion->setCharacterSize(20);
        NumFotoPocion->setString("1");
        NumFotoPocion->setPosition(535,390);
        
       
        ///////////////////////////////
	/*menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Mejorar armadura");
        menu[0].setRotation(-5);
	menu[0].setPosition(sf::Vector2f(200, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));*/
        textoComprarArmadura = new sf::Text();
        textoComprarArmadura->setFont(*font);
        textoComprarArmadura->setColor(sf::Color::Red);
        textoComprarArmadura->setString("Mejorar armadura");
        textoComprarArmadura->setRotation(-5);
        textoComprarArmadura->setPosition(sf::Vector2f(200, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
        
        sprite[0] = new sf::Sprite(*armadura);
        sprite[0]->setPosition(sf::Vector2f(600, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	/*menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Mejorar arma");
        menu[1].setRotation(5);
	menu[1].setPosition(sf::Vector2f(200, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));*/
        textoComprarArma = new sf::Text();
        textoComprarArma->setFont(*font);
        textoComprarArma->setColor(sf::Color::White);
        textoComprarArma->setString("Mejorar arma");
        textoComprarArma->setRotation(5);
        textoComprarArma->setPosition(sf::Vector2f(200, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
        
        sprite[1] = new sf::Sprite(*arma);
        sprite[1]->setPosition(sf::Vector2f(600, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	/*menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Comprar pocion");
        menu[2].setRotation(-5);
	menu[2].setPosition(sf::Vector2f(200, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));*/
        textoComprarPociones = new sf::Text();
        textoComprarPociones->setFont(*font);
        textoComprarPociones->setColor(sf::Color::White);
        textoComprarPociones->setString("Comprar pocion");
        textoComprarPociones->setRotation(-5);
        textoComprarPociones->setPosition(sf::Vector2f(200, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
        
        sprite[2] = new sf::Sprite(*pocion);
        sprite[2]->setPosition(sf::Vector2f(600, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
        
        /*menu[3].setFont(font);
	menu[3].setColor(sf::Color::White);
	menu[3].setString("Salir");
	menu[3].setPosition(sf::Vector2f(200 / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));
        menu[3].setRotation(5);*/
        textoSalir = new sf::Text();
        textoSalir->setFont(*font);
        textoSalir->setColor(sf::Color::White);
        textoSalir->setString("Salir");
        textoSalir->setRotation(5);
        textoSalir->setPosition(sf::Vector2f(90, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));


	selectedItemIndex = 0;
}


Menu::~Menu()
{
     for(int i=0; i<3; i++){
        delete sprite[i];
    }
    delete[] sprite;
    delete armadura;
    delete arma;
    delete pocion;
    
    delete textoComprarArmadura;
    delete textoComprarArma;
    delete textoComprarPociones;
    delete textoSalir;
    
    delete textoDinero;
    delete NumDinero;
    delete textoPocion;
    delete NumPociones;
    delete textoDanyo;
    delete NumDanyo;
    delete textoDefensa;
    delete NumDefensa;
    delete PrecioFotoDefensa;
    delete NumFotoDefensa;
    delete PrecioFotoDanyo;
    delete NumFotoDanyo;
    delete PrecioFotoPocion;
    delete NumFotoPocion;
    
    delete soundShop;
    delete bufferShop;
    
    delete font;
}

void Menu::draw(sf::RenderWindow &window)
{
        window.draw(bg);
        window.draw(*textoDinero);
        NumDinero->setString(int2Str(dinero));
        window.draw(*NumDinero);
        window.draw(*textoPocion);
        NumPociones->setString(int2Str(pociones));
        window.draw(*NumPociones);
        window.draw(*textoDanyo);
        NumDanyo->setString(int2Str(danyo));
        window.draw(*NumDanyo);
        window.draw(*textoDefensa);
        NumDefensa->setString(int2Str(defensa));
        window.draw(*NumDefensa);
        
        PrecioFotoDefensa->setString(int2Str(fotoPrecioDefensa));
        window.draw(*PrecioFotoDefensa);
        NumFotoDefensa->setString(int2Str(fotoNumDefensa));
        window.draw(*NumFotoDefensa);
        
        PrecioFotoDanyo->setString(int2Str(fotoPrecioDanyo));
        window.draw(*PrecioFotoDanyo);
        NumFotoDanyo->setString(int2Str(fotoNumDanyo));
        window.draw(*NumFotoDanyo);
        
        window.draw(*PrecioFotoPocion);
        window.draw(*NumFotoPocion);
        
        //opciones menu
        window.draw(*textoComprarArmadura);
        window.draw(*textoComprarArma);
        window.draw(*textoComprarPociones);
        window.draw(*textoSalir);
        
        for (int i = 0; i < 3; i++)
	{
                window.draw(*sprite[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
            if(selectedItemIndex == 1){
                textoComprarArma->setColor(sf::Color::White);
                selectedItemIndex--;
                textoComprarArmadura->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 2){
                textoComprarPociones->setColor(sf::Color::White);
                selectedItemIndex--;
                textoComprarArma->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 3){
                textoSalir->setColor(sf::Color::White);
                selectedItemIndex--;
                textoComprarPociones->setColor(sf::Color::Red);
            }
		
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
            if(selectedItemIndex == 0){
                textoComprarArmadura->setColor(sf::Color::White);
                selectedItemIndex++;
                textoComprarArma->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 1){
                textoComprarArma->setColor(sf::Color::White);
                selectedItemIndex++;
                textoComprarPociones->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 2){
                textoComprarPociones->setColor(sf::Color::White);
                selectedItemIndex++;
                textoSalir->setColor(sf::Color::Red);
            }
	}
}
void Menu::BuyItem(int n)
{
    if(dinero>0){
        if(n==0 && dinero>=fotoPrecioDefensa){
        dinero = dinero-fotoPrecioDefensa; 
        defensa = defensa+5;
        fotoPrecioDefensa = fotoPrecioDefensa*2;
        }
        if(n==1 && dinero>=fotoPrecioDanyo){
           dinero = dinero-fotoPrecioDanyo; 
           danyo = danyo+5; 
           fotoPrecioDanyo = fotoPrecioDanyo*2;
        }
        if(n==2 && dinero>=50 && pociones<9){
           dinero = dinero-50; 
           pociones = pociones+1; 
        }
    }
    
}

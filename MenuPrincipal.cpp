#include "MenuPrincipal.h"
#include <iostream>
#include <sstream>
#include <string>
#include <SFML/Audio.hpp>

#define kVel 5


static inline std::string int2Str(int x)
{
    std::stringstream type;
    type << x;
    return type.str();
}

MenuPrincipal::MenuPrincipal(float width, float height) {
    page=0;//pagina de inicio
    font = new sf::Font();
    buffer = new sf::SoundBuffer();
    sound = new sf::Sound();   
    pBackground  = new sf::Texture();
    menuPrincipalFondo = new sf::Texture();
    menuAboutUsFondo = new sf::Texture();
    menuOpcionesFondo = new sf::Texture();
    bg = new sf::RectangleShape();
    
    if (!font->loadFromFile("resources/arial.ttf")){
            std::cerr << "Error cargando la fuente arial.ttf";
            exit(0);
    }
    if (!menuPrincipalFondo->loadFromFile("resources/menuPrincipal.png"))
    {
        std::cerr << "Error cargando la imagen menuPrincipal.png";
        exit(0);
    }
    if (!menuAboutUsFondo->loadFromFile("resources/menuAboutUs.png"))
    {
        std::cerr << "Error cargando la imagen menuAboutUs.png";
        exit(0);
    }
    if (!menuOpcionesFondo->loadFromFile("resources/menuOpcionesFondo.png"))
    {
        std::cerr << "Error cargando la imagen menuOpcionesFondo.png";
        exit(0);
    }

    pBackground = menuPrincipalFondo;
    bg->setSize(sf::Vector2f(800,600));
    bg->setTexture(pBackground, true);
    /*text = new sf::Text();
    text->setFont(*font);
    text->setColor(sf::Color::White);
    text->setPosition(310,209);
    text->setCharacterSize(30);*/
    //SONIDO//
    soundVolume=100;
    if (!buffer->loadFromFile("resources/sound2.ogg")){
        std::cerr << "Error cargando el audio sound2.ogg";
        exit(0);
    }

    sound->setBuffer(*buffer);
    sound->play();
    sound->setVolume(soundVolume);
    texnuevaPartida = new sf::Text();
    texnuevaPartida->setFont(*font);
    texnuevaPartida->setColor(sf::Color::Red);
    texnuevaPartida->setString("Nueva Partida");
    texnuevaPartida->setPosition(225,200);
        
    texopciones = new sf::Text();
    texopciones->setFont(*font);
    texopciones->setColor(sf::Color::White);
    texopciones->setString("Opciones");
    texopciones->setPosition(225,300);
        
    texaboutUs = new sf::Text();
    texaboutUs->setFont(*font);
    texaboutUs->setColor(sf::Color::White);
    texaboutUs->setString("About Us");
    texaboutUs->setPosition(225,400);
        
    texsalir = new sf::Text();
    texsalir->setFont(*font);
    texsalir->setColor(sf::Color::White);
    texsalir->setString("Salir");
    texsalir->setPosition(225,500);
    
    texsatras = new sf::Text();
    texsatras->setFont(*font);
    texsatras->setColor(sf::Color::Red);
    texsatras->setString("Atras");
    texsatras->setPosition(40,550);
    
    selectedItemIndex = 0;
    
    
}
void MenuPrincipal::draw(sf::RenderWindow &window)
{
    if(page==0){
        pBackground = menuPrincipalFondo;
        bg->setTexture(pBackground, true);
        window.draw(*bg);

        //opciones menu
        window.draw(*texnuevaPartida);
        window.draw(*texopciones);
        window.draw(*texaboutUs);
        window.draw(*texsalir);
    }
    if (page==2){
        pBackground = menuOpcionesFondo;
        bg->setTexture(pBackground, true);
        window.draw(*bg);
        window.draw(*texsatras);
    }
    if (page==3){
        pBackground = menuAboutUsFondo;
        bg->setTexture(pBackground, true);
        window.draw(*bg);
        window.draw(*texsatras);
    }
        
        

}

void MenuPrincipal::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
            if(selectedItemIndex == 1){
                texopciones->setColor(sf::Color::White);
                selectedItemIndex--;
                texnuevaPartida->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 2){
                texaboutUs->setColor(sf::Color::White);
                selectedItemIndex--;
                texopciones->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 3){
                texsalir->setColor(sf::Color::White);
                selectedItemIndex--;
                texaboutUs->setColor(sf::Color::Red);
            }
		
	}
}

void MenuPrincipal::MoveDown()
{
	if (selectedItemIndex + 1 < 4)
	{
            if(selectedItemIndex == 0){
                texnuevaPartida->setColor(sf::Color::White);
                selectedItemIndex++;
                texopciones->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 1){
                texopciones->setColor(sf::Color::White);
                selectedItemIndex++;
                texaboutUs->setColor(sf::Color::Red);
            }else
            if(selectedItemIndex == 2){
                texaboutUs->setColor(sf::Color::White);
                selectedItemIndex++;
                texsalir->setColor(sf::Color::Red);
            }
	}
}

void MenuPrincipal::SetPage(int n)
{
    page=n;
    
}

bool MenuPrincipal::HandleEvents(sf::RenderWindow &window){
	sf::Event event;

	while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
                                    if(page==0)
					this->MoveUp();
					break;

				case sf::Keyboard::Down:
                                    if(page==0)
					this->MoveDown();
					break;
                                        
                                case sf::Keyboard::Left:
                                    if(page==2)
					if(soundVolume>0){
                                            soundVolume=soundVolume-10;
                                            sound->setVolume(soundVolume);
                                        }
					break;

				case sf::Keyboard::Right:
                                    if(page==2)
					if(soundVolume<100){
                                            soundVolume=soundVolume+10;
                                            sound->setVolume(soundVolume);
                                        }
					break;
                                        
                                case sf::Keyboard::Space:
                                    if(page==2)
					if(soundVolume!=0){
                                            soundVolume=0;
                                            sound->setVolume(soundVolume);
                                        }
                                        else {
                                            soundVolume=100;
                                            sound->setVolume(soundVolume);
                                        }
					break;


				case sf::Keyboard::Return:
                                    if(page==0){
					switch (this->GetPressedItem())
					{
					case 0:
						std::cout << "Nueva Partida" << std::endl;
                                                //this->SetPage(1);//pag nueva partida
                                                return true;
						break;
					case 1:
						std::cout << "Opciones" << std::endl;
                                                this->SetPage(2);//pag nueva partida
						break;
                                        case 2:
						std::cout << "About Us" << std::endl;
                                                this->SetPage(3);//pag nueva partida
						break;
					case 3:
						window.close();
						break;
					}

					break;
                                    }else if(page==3 || page==2){
                                        std::cout << "Menu Principal" << std::endl;
                                        this->SetPage(0);//pag nueva partida
                                        break;
                                    }
                                }

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}
        return false;
}

MenuPrincipal::~MenuPrincipal() {
    delete texnuevaPartida;
    delete texopciones;
    delete texaboutUs;
    delete texsalir;
    delete sound;
    delete buffer;
    delete menuPrincipalFondo;
    delete menuAboutUsFondo;
    delete menuOpcionesFondo;
    delete pBackground;
    delete bg;
}


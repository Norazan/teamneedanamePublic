#ifndef GATE2158_MENU_H
#define GATE2158_MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UserInput.h"

class Menu{
public:
	Menu(sf::RenderWindow &windowRef, bool showMenu);
	void draw();
	void processKeys();
	bool getShowingMenu();
private:
	sf::RenderWindow &window;
	bool showingMenu;
	int currentSelection;
	bool splashScreen;
	UserInput input;
	sf::Vector2f startLocation{ 1280 / 2 - 200 / 2, 400 };
	sf::Vector2f quitLocation{ 1280 / 2 - 200 / 2, 550 };
	sf::Texture gameLogoTexture;
	sf::Texture logoTexture;
	sf::Texture startTexture;
	sf::Texture quitTexture;
	sf::Music menuBackgroundMusic;
};


#endif
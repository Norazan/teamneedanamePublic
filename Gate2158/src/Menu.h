#ifndef GATE2158_MENU_H
#define GATE2158_MENU_H

#include <SFML/Graphics.hpp>

class Menu{
public:
	Menu(sf::RenderWindow &windowRef);
	void show(bool showMenu);
	int getCurrentSelection();
	void setCurrentSelection(int selection);
	void skipSplashScreen();

protected:
	sf::RenderWindow &window;
	bool showingMenu;
	int currentSelection;
	bool splashScreen;
};


#endif
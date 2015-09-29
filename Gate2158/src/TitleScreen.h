#ifndef GATE2158_TITLESCREEN_H
#define GATE2158_TITLESCREEN_H

#include "Menu.h"

class TitleScreen{
public:
	void drawTitle();
protected:
	sf::RenderWindow &window;
	bool showingMenu;

};

#endif
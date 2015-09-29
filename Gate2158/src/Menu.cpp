#include "Menu.h"

void Menu::show(bool showMenu, sf::RenderWindow &windowRef){
	if (showMenu){
		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Red);
		windowRef.draw(shape);
	}
}
//
// Created by ole on 10/3/15.
//

#include "Text.h"

Text::Text(std::string t, sf::Vector2f pos, sf::Text::Style style, sf::Color color, int size, std::string f ):
	drawable(pos)
{
	text.setString(t);
	text.setStyle(style);
	text.setColor(color);
	text.setCharacterSize(size);
	sf::Font font;
	std::cout << "hallo\n";
	if (!font.loadFromFile("C:/Users/Ole/Documents/GitHub/teamneedaname/Gate2158/media/Another_America.ttf")){
		std::cout << "error: can't load the font.";
	}
	text.setFont(font);
}

void Text::draw(sf::RenderWindow &window){
	text.setPosition(getPosition());
	window.draw(text);
}
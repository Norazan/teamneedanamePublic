//
// Created by ole on 10/3/15.
//

#include "Text.h"

Text::Text(std::string t, sf::Vector2f pos, sf::Text::Style style, sf::Color color, int size, std::string f) :
drawable(pos)
{
	text.setString(t);
	text.setStyle(style);
	text.setColor(color);
	text.setCharacterSize(size);
	sf::Font font;
	std::cout << "hallo\n";
	if (!font.loadFromFile("../../Gate2158/media/Another_America.ttf")){
		std::cout << "error: can't load the font.";
	}
	text.setFont(font);
}

Text::Text(
	sf::String t,
	sf::Vector2f pos,
	sf::Text::Style style,
	sf::Color color,
	int size,
	sf::Font *font
	) :drawable(pos){

	text.setString(t);
	text.setPosition(pos);
	text.setStyle(style);
	text.setColor(color);
	text.setCharacterSize(size);
	text.setFont(*font);
	
}

void Text::draw(sf::RenderWindow &window){
	text.setPosition(getPosition());
	window.draw(text);
}

sf::Vector2f Text::getSize(){
	sf::Vector2f size;
	size.x = text.getLocalBounds().width;
	size.y = text.getLocalBounds().height;
	return size;
}

float Text::getAngle(){
	return text.getRotation();
}

void Text::rotate(float rotation){
	sf::Vector2f size = getSize();
	sf::Vector2f center;
	center.x = size.x / 2;
	center.y = size.y / 2;
	text.setOrigin(center);
	text.rotate(rotation);
}
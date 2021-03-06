//
// Created by ole on 10/3/15.
//

#include "Text.h"

Text::Text(
	std::string t,
	sf::Vector2f pos,
	sf::Text::Style style,
	sf::Color color,
	int size,
	sf::Font *font
){
	text.setString(t);
	text.setStyle(style);
	text.setColor(color);
	text.setCharacterSize(size);
	text.setFont(*font);
}

void Text::draw(sf::RenderWindow &window, sf::Vector2f &position){
	text.setPosition(position);
	window.draw(text);
}

sf::Vector2f Text::getSize(){
	sf::Vector2f size;
	size.x = text.getLocalBounds().width;
	size.y = text.getLocalBounds().height;
	return size;
}

float Text::getRotation(){
	return text.getRotation();
}

void Text::setRotation(float rotation){
	text.setRotation(rotation);
}

void Text::setText(std::string s){
	text.setString(s);
}
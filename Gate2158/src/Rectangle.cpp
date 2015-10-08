//
// Created by ole on 10/1/15.
//

#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color color):
	drawable(pos)
{
	rectangle.setSize(size);
	rectangle.setFillColor(color);
	sf::Vector2f s = getSize();
	sf::Vector2f center{ s.x / 2, s.y / 2 };
	rectangle.setOrigin(center);
}

void Rectangle::draw(sf::RenderWindow &window){
	rectangle.setPosition(getPosition());
	window.draw(rectangle);
}

sf::Vector2f Rectangle::getSize(){
	return rectangle.getSize();
}

float Rectangle::getRotation(){
	return rectangle.getRotation();
}

void Rectangle::setRotation(float rotation){
	rectangle.setRotation(rotation);
}
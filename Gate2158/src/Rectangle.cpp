//
// Created by ole on 10/1/15.
//

#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f pos, sf::Vector2f size, sf::Color color):
	drawable(pos)
{
	rectangle.setSize(size);
	rectangle.setFillColor(color);
}

void Rectangle::draw(sf::RenderWindow &window){
	rectangle.setPosition(getPosition());
	window.draw(rectangle);
}

sf::Vector2f Rectangle::getSize(){
	return rectangle.getSize();
}

float Rectangle::getAngle(){
	return rectangle.getRotation();
}

void Rectangle::rotate(float rotation){
	sf::Vector2f size = getSize();
	sf::Vector2f center;
	center.x = size.x / 2;
	center.y = size.y / 2;
	rectangle.setOrigin(center);
	rectangle.rotate(rotation);
}
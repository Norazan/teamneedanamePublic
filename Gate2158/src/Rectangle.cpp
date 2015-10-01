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
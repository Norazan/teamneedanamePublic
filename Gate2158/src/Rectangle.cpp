//
// Created by ole on 10/1/15.
//

#include "Rectangle.h"

Rectangle::Rectangle(sf::Vector2f size, sf::Color color):
	drawable()
{
	rectangle.setSize(size);
	rectangle.setFillColor(color);
}

void Rectangle::draw(sf::RenderWindow &window, sf::Vector2f &position){
	rectangle.setPosition(position);
	window.draw(rectangle);
}
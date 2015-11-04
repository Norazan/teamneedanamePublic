//
// Created by ole on 10/6/15.
//

#include "Circle.h"

Circle::Circle(float radius, sf::Color color)
{
	circle.setRadius(radius);
	circle.setFillColor(color);
	sf::Vector2f size = getSize();
	sf::Vector2f center{ size.x / 2, size.y / 2 };
	circle.setOrigin(center);
}

void Circle::draw(sf::RenderWindow &window, sf::Vector2f position){
	circle.setPosition(position);
	window.draw(circle);
}

sf::Vector2f Circle::getSize(){
	sf::Vector2f size;
	size.x = circle.getLocalBounds().width;
	size.y = circle.getLocalBounds().height;
	return size;
}

float Circle::getRotation(){
	return circle.getRotation();
}

void Circle::setRotation(float rotation){
	circle.setRotation(rotation);
}
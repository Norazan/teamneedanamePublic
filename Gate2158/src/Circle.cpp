//
// Created by ole on 10/6/15.
//

#include "Circle.h"

Circle::Circle(sf::Vector2f pos, float radius, sf::Color color) :
	drawable(pos)
{
	circle.setRadius(radius);
	circle.setFillColor(color);
}

void Circle::draw(sf::RenderWindow &window){
	circle.setPosition(getPosition());
	window.draw(circle);
}

sf::Vector2f Circle::getSize(){
	sf::Vector2f size;
	size.x = circle.getLocalBounds().width;
	size.y = circle.getLocalBounds().height;
	return size;
}

float Circle::getAngle(){
	return circle.getRotation();
}

void Circle::rotate(float rotation){
	sf::Vector2f size = getSize();
	sf::Vector2f center;
	center.x = size.x / 2;
	center.y = size.y / 2;
	circle.setOrigin(center);
	circle.rotate(rotation);
}
//
// Created by Jordan on 26-10-2015
//

#include "Convex.h"

Convex::Convex(sf::Vector2f position):
drawable(position)
{
	convex.setPosition(sf::Vector2f(200, 200));
	convex.setPointCount(4);

	convex.setPoint(0, sf::Vector2f(30, 50));
	convex.setPoint(1, sf::Vector2f(40, 18));
	convex.setPoint(2, sf::Vector2f(80, 50));
	convex.setPoint(3, sf::Vector2f(40, 75));
	//convex.setPoint(4, sf::Vector2f(0, 50));

	convex.setOrigin(sf::Vector2f(50, 50));
	//convex.setRotation(45.0);
	convex.setFillColor(sf::Color(0, 255, 0, 0)); //Green, for the hitbox the last value (alpha) needs to be 0 (transparent);
	convex.setOutlineThickness(1.0);
	convex.setOutlineColor(sf::Color(0, 255, 0, 255));
}

void Convex::draw(sf::RenderWindow & window){
	convex.setPosition(drawable::getPosition());
	window.draw(Convex::convex);
}

float Convex::getRotation(){
	return convex.getRotation();
}
void Convex::setRotation(float rotation){
	convex.setRotation(rotation);
}
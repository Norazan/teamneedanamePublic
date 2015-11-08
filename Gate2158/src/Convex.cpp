//
// Created by Jordan on 26-10-2015
//

#include "Convex.h"
#include <iostream>

Convex::Convex(std::vector<sf::Vector2f> points, sf::Vector2f position) : 
	points(points)
{
	int count = 0;
	convex.setPointCount(points.size());
	for (auto & point : points){
		convex.setPoint(count++, point);
	}
}

Convex::Convex(std::vector<sf::Vector2f> points, sf::Vector2f position, sf::Vector2f center) :
	points(points)
{
	int count = 0;
	convex.setOrigin(center);
	convex.setPointCount(points.size());
	for (auto & point : points){
		convex.setPoint(count++, point);
	}
	convex.setFillColor(sf::Color::Transparent);
/*
	sf::Vector2f size = getSize();
	position.x += ((size.x - 90) / 10) * -5;
	position.y += ((size.y - 50) / 10) * -5;
	setPosition(position);*/
}

std::vector<sf::Vector2f>& Convex::getPoints(){
	return points;
}


void Convex::draw(sf::RenderWindow & window, sf::Vector2f &position){
	convex.setPosition(position);
	window.draw(convex);
}

float Convex::getRotation(){
	return convex.getRotation();
}
void Convex::setRotation(float rotation){
	convex.setRotation(rotation);
}

sf::Vector2f Convex::getOrigin(){
	return convex.getOrigin();
}

sf::Vector2f Convex::getSize(){
	return sf::Vector2f{ getOrigin().x * 2, getOrigin().y * 2 };
}
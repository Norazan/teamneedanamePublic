//
// Created by Jordan on 26-10-2015
//

#include "Convex.h"

Convex::Convex(std::vector<sf::Vector2f> points, sf::Vector2f position) : 
	drawable{ position }
{
	int count = 0;
	convex.setPointCount(points.size());
	for (auto & point : points){
		convex.setPoint(count++, point);
	}
}

Convex::Convex(std::vector<sf::Vector2f> points, sf::Vector2f position, sf::Vector2f center) :
	drawable{ position }
{
	int count = 0;
	convex.setOrigin(center);
	convex.setPointCount(points.size());
	for (auto & point : points){
		convex.setPoint(count++, point);
	}
	convex.setFillColor(sf::Color::Blue);
	updatePoints();
}

void Convex::updatePoints(){
	int pointCount = convex.getPointCount();
	points.clear();
	for (int i = 0; i < pointCount; i++){
		points.push_back(convex.getPoint(i));
	}
}

std::vector<sf::Vector2f>& Convex::getPoints(){
	updatePoints();
	return points;
}

void Convex::setPostion(sf::Vector2f pos){
	convex.setPosition(pos);
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

sf::Vector2f Convex::getOrigin(){
	return convex.getOrigin();
}
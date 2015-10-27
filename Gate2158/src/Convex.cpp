//
// Created by ole on 10/27/15.
//

#include "Convex.h"

Convex::Convex(std::vector<sf::Vector2f> points) : 
	points{points} 
{
	int count = 0;
	polygon.setPointCount(points.size());
	for (auto & point : points){
		polygon.setPoint(count++, point);
	}
}

Convex::~Convex(){

}

std::vector<sf::Vector2f>& Convex::getPoints(){
	return points;
}

void Convex::setPostion(sf::Vector2f pos){
	polygon.setPosition(pos);
}
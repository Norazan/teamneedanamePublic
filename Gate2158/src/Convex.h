//
// Created by jordan on 10/26/15.
//

#ifndef GATE2158_CONVEX_H
#define GATE2158_CONVEX_H

#include <SFML/Graphics.hpp>
#include <vector>

class Convex {
public:
	Convex(std::vector<sf::Vector2f> points);
	~Convex();
	std::vector<sf::Vector2f>& getPoints();
	void setPostion(sf::Vector2f pos);
private:
	sf::ConvexShape polygon;
	std::vector<sf::Vector2f> points;
};

#endif
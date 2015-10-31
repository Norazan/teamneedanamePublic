//
// Created by jordan on 10/26/15.
//

#ifndef GATE2158_CONVEX_H
#define GATE2158_CONVEX_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "drawable.h"

class Convex : public drawable{
public:
	Convex(std::vector<sf::Vector2f> points, sf::Vector2f position);
	Convex(std::vector<sf::Vector2f> points, sf::Vector2f position, sf::Vector2f center);
	void draw(sf::RenderWindow &window) override;
	float getRotation() override;
	void setRotation(float rotation) override;
	sf::Vector2f getSize() override;
	std::vector<sf::Vector2f>& getPoints();
	void setPostion(sf::Vector2f pos);
	sf::Vector2f getOrigin();
private:
	sf::ConvexShape convex;
	std::vector<sf::Vector2f> points;
};

#endif GATE2158_CONVEX_H

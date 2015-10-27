//
// Created by ole on 10/6/15.
//

#ifndef GATE2158_CONVEX_H
#define GATE2158_CONVEX_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Convex : public drawable {
public:
	Convex(sf::Vector2f position);
	void draw(sf::RenderWindow &window) override;
	sf::Vector2f getSize() override;
	float getRotation() override;
	void setRotation(float rotation) override;
private:
	sf::ConvexShape convex;
};

#endif //GATE2158_CIRCLE_H
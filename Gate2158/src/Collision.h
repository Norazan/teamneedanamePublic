//
// Created by Ole on 10/26/15.
//

#ifndef GATE2158_COLLISION_H
#define GATE2158_COLLISION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "MapObject.h"


class Collision {
public:
	// returns 1 if collision is detected otherwise it returns 0;
	float checkCollision(MapObject & ob1, MapObject & ob2);

private:
	struct line {
		sf::Vector2f position_1;
		sf::Vector2f position_2;
	};

	// returns a vector with all the axes of the lines of an object.
	std::vector<line> getAxes(MapObject &mo);

	// returns the overlap of the to objects on the axes.
	float getOverlapOnAxes(line axes, MapObject & obj1, MapObject & obj2);

	// returns the projection on a axes.
	line getProjection(float a, MapObject & mo, std::vector<sf::Vector2f> convexPoints, line axes);
};

#endif
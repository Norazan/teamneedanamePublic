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

	// returns a vector with all the lines of the object.
	std::vector<line> getLines(MapObject & mo);

	// returns a vector with all the axes of the lines of an object.
	std::vector<line> getAxes(std::vector<line> & lines);

	// returns the overlap of the to objects on the axes.
	float getOverlapOnAxes(line axes, MapObject & obj1, MapObject & obj2);
	
};

#endif
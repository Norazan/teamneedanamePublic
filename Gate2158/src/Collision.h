//
// Created by Ole on 10/26/15.
//

#ifndef GATE2158_COLLISION_H
#define GATE2158_COLLISION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "MapObject.h"


class Collision {
public:
	// returns 1 if collision is detected otherwise it returns 0;
	int checkCollision(MapObject & ob1, MapObject & ob2);

	// 1. take every line of the two shapes
	// 2. make axis from the lines, by normalize the line.
	// 3. make for every axis a projection of the shapes.
	// 4. if on every axis the projections overlap, the shapes are intersecting.
	// 5. the axis where the smallest overlap is, is the line where the shapes are intersecting.


private:
	struct line {
		sf::Vector2f position_1;
		sf::Vector2f position_2;
	};

	// returns a vector with all the lines of the object.
	std::vector<line> getLines(MapObject & mo);

	// returns a vector with all the axes of the lines of an object.
	std::vector<line> getAxes(std::vector<line> lines);

	// returns the projection
	line getProjection(line axes, std::vector<line> lines );

	// returns the overlap
	int overlap(line projection_1, line projection_2);
	
};

#endif
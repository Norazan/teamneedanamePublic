/**
* @file Collision.h
* @author Ole
* @date 10/26/15
* @version 1.0
*
* The Collision class to check if two MapObjects have collision.
* A lot of code is comment, to create more speed in our program.
* If the collision needs to give the points of the colliding line, the comment code can be uncomment.
*/

#ifndef GATE2158_COLLISION_H
#define GATE2158_COLLISION_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "MapObject.h"


class Collision {
public:
	/**
	* Checked the collision on two MapObjects
	*
	* @param ob1
	*		The fist MapObject
	* @param ob2
	*		The second MapObject
	* @return
	*		Boolean if the Objects are colliding
	*/
	float checkCollision(MapObject & ob1, MapObject & ob2);

private:
	/**
	* Struct line, to make a line between two points.
	*/
	struct line {
		sf::Vector2f position_1; /**< struct value position 1 of line */
		sf::Vector2f position_2; /**< struct value position 2 of line */
	};
	/**
	* Returns the overlap between two MapObjects on a axes
	*
	* @param axes
	*		The axes where the overlap is calculated
	* @param obj1
	*		The first object
	* @param obj2
	*		The second object
	* @retun
	*		The overlap between the objects
	*/
	float getOverlapOnAxes(line axes, MapObject & obj1, MapObject & obj2);
	/**
	* Makes a projection on a axes
	*
	* @param axes
	*		The axes where the projection needs to be
	* @param convexPoints
	*		The points of the object
	* @retun
	*		The projection on the axes
	*/
	line getProjection(std::vector<sf::Vector2f> convexPoints, line axes);

};

#endif
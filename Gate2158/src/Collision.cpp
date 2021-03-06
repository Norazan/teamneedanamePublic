//
// Created by Ole on 10/26/15.
//

#include "Collision.h"
#include <vector>
#include <iostream>
#include <math.h>

struct line {
	sf::Vector2f position_1;
	sf::Vector2f position_2;
};

float Collision::checkCollision(MapObject & obj1, MapObject & obj2){
	sf::Vector2f sizeObj1 = obj1.getSize();
	sf::Vector2f sizeObj2 = obj2.getSize();
	sf::Vector2f posObj1 = obj1.getDrawPosition();
	sf::Vector2f posObj2 = obj2.getDrawPosition();

	float lenghtObj1 = sqrt(pow(sizeObj1.x/2, 2) + pow(sizeObj1.y/2, 2));
	float lenghtObj2 = sqrt(pow(sizeObj2.x/2, 2) + pow(sizeObj2.y/2, 2));
	float length = lenghtObj1 + lenghtObj2;
	sf::Vector2f posDiff;
	posDiff.x = abs(posObj1.x - posObj2.x);
	posDiff.y = abs(posObj1.y - posObj2.y);
	float diffDistance = sqrt(pow(posDiff.x, 2) + pow(posDiff.y, 2));
	if (diffDistance > length){
		return 0;
	}

	//std::vector<line> axes_obj1 = getAxes(obj1);
	std::vector<sf::Vector2f> pointsObj1 = obj1.getConvexPoints();
	int size = pointsObj1.size();
	line axes_obj1[10];
	for (int i = 0; i < size; i++){
		line newAxes;
		// make line from current point and next point
		// and make from the line, an axes that is perpendicular to the line, 
		// simples way to do this is by swapping x and y and make y negative ( -y, x ).
		if (i < (size - 1)){
			newAxes = {
				sf::Vector2f{ -pointsObj1[i].y, pointsObj1[i].x },
				sf::Vector2f{ -pointsObj1[i + 1].y, pointsObj1[i + 1].x }
			};
		}
		// make line from last point and first point.
		else {
			newAxes = {
				sf::Vector2f{ -pointsObj1[i].y, pointsObj1[i].x },
				sf::Vector2f{ -pointsObj1[0].y, pointsObj1[0].x }
			};
		}
		axes_obj1[i] = newAxes;
	}
	//std::vector<line> axes_obj2 = getAxes(obj2);
	std::vector<sf::Vector2f> pointsObj2 = obj2.getConvexPoints();
	size = pointsObj1.size();
	line axes_obj2[10];
	for (int i = 0; i < size; i++){
		line newAxes;
		// make line from current point and next point
		// and make from the line, an axes that is perpendicular to the line, 
		// simples way to do this is by swapping x and y and make y negative ( -y, x ).
		if (i < (size - 1)){
			newAxes = {
				sf::Vector2f{ -pointsObj1[i].y, pointsObj1[i].x },
				sf::Vector2f{ -pointsObj1[i + 1].y, pointsObj1[i + 1].x }
			};
		}
		// make line from last point and first point.
		else {
			newAxes = {
				sf::Vector2f{ -pointsObj1[i].y, pointsObj1[i].x },
				sf::Vector2f{ -pointsObj1[0].y, pointsObj1[0].x }
			};
		}
		axes_obj2[i] = newAxes;
	}
	// loop over the axes1
	//float smallest_overlap = 500;
	//int smalles_overlap_on_axes_obj1 = 0, smalles_overlap_on_axes_obj2 = 0, axesCount = 0;
	for (auto & axes : axes_obj1) {
		// do the projections overlap on the axes?
		if (obj1.getHitbox() == nullptr && obj2.getHitbox() == nullptr){
			return 0;
		}
		float overlap = getOverlapOnAxes(axes, obj1, obj2);
		if (overlap == 0) {
			// there is no overlap..
			return 0;
		} 
		/*
		else if (overlap < smallest_overlap){
			smallest_overlap = overlap;
			smalles_overlap_on_axes_obj1 = axesCount;
		}
		++axesCount; 
		*/
	}
	// loop over the axes2
	//axesCount = 0;
	for (auto & axes : axes_obj2) {
		// do the projections overlap on the axes?
		float overlap = getOverlapOnAxes(axes, obj1, obj2);
		if (overlap == 0) {
			// there is no overlap..
			return 0;
		}
		/*
		else if (overlap < smallest_overlap){
			smallest_overlap = overlap;
			smalles_overlap_on_axes_obj2 = axesCount;
		}
		++axesCount; 
		*/
	}
	// if smalles overlap is not changed by object 2 overlap in on object 1
	/*
	line intersecting_line;
	if (smalles_overlap_on_axes_obj2 == 0){
		intersecting_line = lines_obj1[smalles_overlap_on_axes_obj1];
	}
	else {
		intersecting_line = lines_obj2[smalles_overlap_on_axes_obj2];
	}
	*/
	obj1.collisionDetected(obj2);
	obj2.collisionDetected(obj1);
	return 1;//smallest_overlap;
}

float Collision::getOverlapOnAxes(line axes, MapObject & obj1, MapObject & obj2){
	const std::vector<sf::Vector2f> &convexPointsObj1 = obj1.getConvexPoints();
	const std::vector<sf::Vector2f> &convexPointsObj2 = obj2.getConvexPoints();
	// there is no convex.
	if (convexPointsObj1.size() == 0 || convexPointsObj2.size() == 0){
		return 0;
	}

	line projectionObj1 = getProjection(convexPointsObj1, axes);
	line projectionObj2 = getProjection(convexPointsObj2, axes);

	float overlap = 0;
	// check the projection overlap
	if (projectionObj2.position_2.x < projectionObj1.position_1.x &&
		projectionObj2.position_2.x < projectionObj1.position_2.x ||
		projectionObj2.position_1.x > projectionObj1.position_1.x &&
		projectionObj2.position_1.x > projectionObj1.position_2.x
	){
		return 0;
	}
	// if overlap, what is the overlap?
	/*
	else if (projectionObj1.position_2.x >= projectionObj2.position_2.x){
		overlap = projectionObj2.position_2.x - projectionObj1.position_1.x;
	}
	else {
		overlap = projectionObj1.position_2.x - projectionObj2.position_1.x;
	}
	// we have the overlap on the x-axes but we have an other axes so we need to know the length relative to our axes.
	float result;
	if (axes.position_1.x == axes.position_2.x){
		result = overlap;
	}
	else {
		result = (overlap / (cos(atan(a))));
	}
	*/
	return 1;//result;
}

Collision::line Collision::getProjection(std::vector<sf::Vector2f> convexPoints, line axes){
	// make a function (y = ax + b ) of the axes that goes through the origin.
	// function gous through the origin when b = 0, only value we don't know is 'a' (a = delta y / delta x)
	float a = (axes.position_1.y - axes.position_2.y) / (axes.position_1.x - axes.position_2.x);
	line projection{ sf::Vector2f{ 0, 0 }, sf::Vector2f{ 0, 0 } };
	for (auto & p : convexPoints) {
		float b, y, x;
		// if axes is the same as the y-axes, we don't need to check x but we need to check y.
		if (axes.position_1.x == axes.position_2.x){
			x = p.y;
		}
		else {
			// make a function that is perpendicular to the axes and goes through the point. (y = -(1/a)x + b)
			// we can fill the point into the function so we can get b. ( b = y + (1/a)x )
			b = p.y + (1 / a) * p.x;

			// where do the two lines cross. (  y = ax  and  y = -(1/a)x + b   so ->  ax = -(1/a)x + b  )
			x = (a * b) / (pow(a, 2) + 1);
			y = a * x;

			// if a = 0, x = x of point.
			if (a == 0){
				x = p.x;
			}
		}
		// save the smallest and the biggest values in projection
		if (projection.position_1.x > x || projection.position_1.x == 0) {
			projection.position_1.x = x;
		}
		if (projection.position_2.x < x || projection.position_2.x == 0){
			projection.position_2.x = x;
		}
	}
	return projection;
}
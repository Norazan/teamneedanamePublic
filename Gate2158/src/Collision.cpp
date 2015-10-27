//
// Created by Ole on 10/26/15.
//

#include "Collision.h"

int Collision::checkCollision(MapObject & obj1, MapObject & obj2){
	std::vector<line> lines_obj1 = getLines(obj1);
	std::vector<line> lines_obj2 = getLines(obj1);
	std::vector<line> axes_obj1 = getAxes(lines_obj1);
	std::vector<line> axes_obj2 = getAxes(lines_obj2);
	// loop over the axes1
	int smallest_overlap = 500, intersecting_axes, count = 0;
	for (auto & axes : axes_obj1) {
		// do the projections overlap on the axes?
		int overlap = getOverlapOnAxes(axes, obj1, obj2);
		if (overlap = 0) {
			// there is no overlap..
			return 0;
		}
		else if(overlap < smallest_overlap){
			smallest_overlap = overlap;
			intersecting_axes = count;
		}
		++count;
	}
	// loop over the axes2
	count = 0;
	for (auto & axes : axes_obj2) {
		// project both shapes onto the axis
		line projection_obj1 = getProjection(axes, obj1);
		line projection_obj2 = getProjection(axes, obj2);
		// do the projections overlap?
		int current_overlap = overlap(projection_obj1, projection_obj2);
		if (current_overlap = 0) {
			// then we can guarantee that the shapes do not overlap
			return 0;
		}
		else if (current_overlap < smallest_overlap){
			smallest_overlap = current_overlap;
			intersecting_axes = count;
		}
		++count;
	}
	// do stuff with it the collision
	return 1;
}

std::vector<Collision::line> Collision::getLines(MapObject & mo){
	std::vector<sf::Vector2f> points = mo.getConvexPoints();
	std::vector<line> lines;
	for (int i = 0; i < points.size(); i++){
		line newline;
		// make line from current point and next point
		if (i < (points.size() - 1)){
			newline = { points[i], points[i + 1] };
		}
		// make line from last point and first point.
		else {
			newline = { points[i], points[0] };
		}
		lines.push_back(newline);
	}
	return lines;
}

std::vector<Collision::line> Collision::getAxes(std::vector<line> lines){
	std::vector<line> axes;
	for (auto & l : lines){
		// axes is perpendicular to the line, 
		// simples way to do this is by swapping x and y and make y negative ( -y, x ).
		line newAxes = { 
			sf::Vector2f{ -l.position_1.y, l.position_1.x },
			sf::Vector2f{ -l.position_2.y, l.position_2.x } 
		};
		axes.push_back(newAxes);
	}
	return axes;
}

int Collision::getOverlapOnAxes(line axes, MapObject & obj1, MapObject & obj2){
	std::vector<sf::Vector2f> convexPointsObj1 = obj1.getConvexPoints();
	std::vector<sf::Vector2f> convexPointsObj2 = obj2.getConvexPoints();
	line projectionObj1{ sf::Vector2f{ 0, 0 }, sf::Vector2f{ 0, 0 } };
	line projectionObj2{ sf::Vector2f{ 0, 0 }, sf::Vector2f{ 0, 0 } };
	// make a function (y = ax + b ) of the axes that goes through the origin.
	// function gous through the origin when b = 0, only value we don't know is 'a' (a = delta y / delta x)
	int a = (axes.position_1.y - axes.position_2.y) / (axes.position_1.x - axes.position_2.y);
	for (auto & p : convexPointsObj1) {
		// make a function that is perpendicular to the axes and goes through the point. (y = -(1/a)x + b)
		// we can fill the point into the function so we can get b. ( b = y + (1/a)x )
		int b = p.y + (1 / a) * p.x;

		// where do the two lines cross. (  y = ax  and  y = -(1/a)x + b   so ->  ax = -(1/a)x + b  )
		int x = (a * b) / (pow(a, 2) + 1);
		int y = a * x;

		// save the smallest and the biggest values in projection 
		if (projectionObj1.position_1.x == 0 || projectionObj1.position_1.x > x) {
			projectionObj1.position_1.x = x;
			projectionObj1.position_1.x = y;
		}
		else if (projectionObj1.position_2.x < x){
			projectionObj1.position_2.x = x;
			projectionObj1.position_2.y = y;
		}
	}
	for (auto & p : convexPointsObj2) {
		// make a function that is perpendicular to the axes and goes through the point. (y = -(1/a)x + b)
		// we can fill the point into the function so we can get b. ( b = y + (1/a)x )
		int b = p.y + (1 / a) * p.x;

		// where do the two lines cross. (  y = ax  and  y = -(1/a)x + b   so ->  ax = -(1/a)x + b  )
		int x = (a * b) / (pow(a, 2) + 1);
		int y = a * x;

		// save the smallest and the biggest values in projection 
		if (projectionObj2.position_1.x == 0 || projectionObj2.position_1.x > x) {
			projectionObj2.position_1.x = x;
		}
		else if (projectionObj2.position_2.x < x){
			projectionObj2.position_2.x = x;
		}
	}
	int overlap = 0;
	// check the projection overlap
	if (projectionObj1.position_1.x < projectionObj2.position_1.x > projectionObj1.position_2.x ||
			projectionObj1.position_1.x < projectionObj2.position_2.x > projectionObj1.position_2.x){
		return 0;
	}
	else if (projectionObj1.position_2.x >= projectionObj2.position_2.x){
		overlap = projectionObj2.position_2.x - projectionObj1.position_1.x;
	}
	else {
		overlap = projectionObj1.position_2.x - projectionObj2.position_1.x;
	}
	// we have the overlap on the x-axes but we have an other axes so we need to know the length relative to our axes.
	return (overlap / (cos(atan(a))));
}
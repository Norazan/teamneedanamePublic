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
		// project both shapes onto the axis
		line projection_obj1 = getProjection(axes, obj1);
		line projection_obj2 = getProjection(axes, obj2);
		// do the projections overlap?
		int current_overlap = overlap(projection_obj1, projection_obj2);
		if (current_overlap = 0) {
			// then we can guarantee that the shapes do not overlap
			return 0;
		}
		else if(current_overlap < smallest_overlap){
			smallest_overlap = current_overlap;
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
	// something with the convex.
}

std::vector<Collision::line> Collision::getAxes(std::vector<line> lines){
	std::vector<line> axes;
	for (auto & l : lines){
		// axes is perpendicular to the line, simples way is to do ( -y, x ).
		line newAxes = { 
			sf::Vector2f{ -l.position_1.y, l.position_1.x },
			sf::Vector2f{ -l.position_2.y, l.position_2.x } 
		};
		axes.push_back(newAxes);
	}
}

Collision::line Collision::getProjection(line axes, MapObject & mo){
	double min = // first point of convex
	double max = min;
	for (int i = 1; i < shape.vertices.length; i++) {
		// NOTE: the axis must be normalized to get accurate projections
		double p = // next point of convex
		if (p < min) {
			min = p;
		}
		else if (p > max) {
			max = p;
		}
	}
	Projection proj = new Projection(min, max);
	return proj;
}

int Collision::overlap(line projection_1, line projection_2){

}
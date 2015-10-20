//
// Created by martijn on 9/29/15.
//

#ifndef GATE2158_CAMERA_HPP
#define GATE2158_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Map.h"


class Camera {
public:
	//! Constructor of Camera
	//
	//! @parameter window
	//! @parameter currenMap
	Camera(sf::RenderWindow &window, Map &currentMap);

	//! Draw function
	//
	//! Drawed all the MapObjects 
	void draw();

private:
	sf::RenderWindow &window;
	Map &currentMap;
};


#endif //GATE2158_CAMERA_HPP

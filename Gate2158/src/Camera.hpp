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

	void addMapObjectToCurrentMap(MapObject *mo);
	void revmoveMapObjectOnCurrentMap(MapObject *mo);
	void checkCollision();

private:
	sf::RenderWindow &window;
	std::vector<MapObject*> removeObjects;
	std::vector<MapObject*> addObjects;
	Map &currentMap;
	bool canCheckCollision = true;
};


#endif //GATE2158_CAMERA_HPP

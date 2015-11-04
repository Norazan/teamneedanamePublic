//
// Created by martijn on 9/29/15.
//

#ifndef GATE2158_CAMERA_HPP
#define GATE2158_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Map.h"
#include "UserCharacter.h"


class Camera {
public:
	//! Constructor of Camera
	//
	//! @parameter window
	//! @parameter currenMap
	Camera(sf::RenderWindow &window, Map &currentMap, MapObject *player);

	//! Draw function
	//
	//! Drawed all the MapObjects 
	void draw();

	std::vector<MapObject*> *getObjectsAroundPlayer();

	void checkCollision();

private:
	sf::RenderWindow &window;
	Map &currentMap;
	MapObject *currentPlayer;
};


#endif //GATE2158_CAMERA_HPP

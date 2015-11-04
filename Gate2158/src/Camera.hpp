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

	static Camera* getInstance();

	//! Draw function
	//
	//! Drawed all the MapObjects 
	void draw();
	void addMapObjectToCurrentMap(MapObject *mo);
	void revmoveMapObjectOnCurrentMap(MapObject *mo);
	void checkCollision();

	void setWindow(sf::RenderWindow &window);
	void setCurrentMap(Map & currentMap);

private:
	//! Constructor of Camera
	//
	//! @parameter window
	//! @parameter currenMap
	//Camera(sf::RenderWindow &window, Map &currentMap);

	Camera();
	static Camera *camera;

	sf::RenderWindow *window;
	std::vector<MapObject*> removeObjects;
	std::vector<MapObject*> addObjects;
	Map *currentMap;
	bool canCheckCollision = true;
};

#endif //GATE2158_CAMERA_HPP

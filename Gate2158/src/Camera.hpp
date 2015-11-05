//
// Created by martijn on 9/29/15.
//

#ifndef GATE2158_CAMERA_H
#define GATE2158_CAMERA_H

#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Map.h"
#include "UserCharacter.h"

class Map;

class Camera {
public:	

	static Camera* getInstance();

	//! Draw function
	//
	//! Drawed all the MapObjects 
	void draw();
	void addMapObjectToCurrentMap(MapObject *mo);
	void revmoveMapObjectOnCurrentMap(MapObject *mo);

	std::vector<MapObject*> *getObjectsAroundPlayer();
	
	void checkCollision();

	void setWindow(sf::RenderWindow &window);
	void setCurrentMap(Map & currentMap);
	void setCurrentPlayer(MapObject *currentPlayer);

	sf::RenderWindow *window;
private:
	//! Constructor of Camera
	//
	//! @parameter window
	//! @parameter currenMap
	//Camera(sf::RenderWindow &window, Map &currentMap);

	Camera();
	static Camera *camera;
	Map *currentMap;
	MapObject *currentPlayer;
	std::vector<MapObject*> removeObjects;
	std::vector<MapObject*> addObjects;
	std::vector<MapObject*> *objectsAroundPlayer;
};

#endif //GATE2158_CAMERA_HPP

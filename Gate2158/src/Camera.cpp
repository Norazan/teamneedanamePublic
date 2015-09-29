//
// Created by martijn on 9/29/15.
//

#include "Camera.hpp"

Camera::Camera(sf::RenderWindow &window, Map &currentMap) :
	window{ window },
	currentMap{currentMap}
{
	
}


void Camera::updateMapObjects(std::vector<MapObject> &mapObjects){
	this->mapObjects = mapObjects;
}

void Camera::draw(){
	for (auto mo : mapObjects){
		mo.draw();
	}
}
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
	int renderLayer = 3;
	for (int i = 0; i < renderLayer; i++){
		for (auto mo : mapObjects){
			if (mo.getRenderLayer == i){
				mo.draw();
			}
		}
	}
}
//
// Created by martijn on 9/29/15.
//

#include "Camera.hpp"

Camera::Camera(sf::RenderWindow &window, Map &currentMap) :
	window{ window },
	currentMap{currentMap}
{
	updateMapObjects();
}


void Camera::updateMapObjects(){
	mapObjects = currentMap.getAllMapObjects();
}

void Camera::draw(){
	updateMapObjects();
	for (int i = currentMap.getLayers; i > 0; i--){
		for (auto mo : mapObjects){
			if (mo.getRenderLayer == i){
				mo.draw(window);
			}
		}
	}
}
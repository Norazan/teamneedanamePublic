//
// Created by martijn on 9/29/15.
//

#include "Camera.hpp"
#include "Collision.h"

Camera::Camera(sf::RenderWindow &window, Map &currentMap) :
	window{ window },
	currentMap{ currentMap }
{
}

void Camera::draw(){
	checkCollision();
	for (int i = currentMap.getLayers(); i >= 0; i--){
		for (auto mo : currentMap.getAllMapObjects()){
			if (mo->getRenderLayer() == i){
				mo->draw(window);
			}
		}
	}
}

void Camera::checkCollision(){
	Collision collision;
	// get all playable objects
	for (auto mo : currentMap.getAllMapObjects()){
		if (mo->getRenderLayer() == 0){
			// check if character has collision with objects
			for (auto object : currentMap.getAllMapObjects()){
				if (object != mo){
					// do nothing with overlap
					(void)collision.checkCollision(*mo, *object);
				}
			}
		}
	}
}
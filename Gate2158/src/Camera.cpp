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
	Collision collision;
	MapObject *last = nullptr;
	for (int i = currentMap.getLayers(); i >= 0; i--){
		for (auto mo : currentMap.getAllMapObjects()){
			if (mo->getRenderLayer() == i){
				mo->draw(window);
				if (last != nullptr){
					collision.checkCollision(*mo, *last);
				}
				last = mo;
			}
		}
	}
}
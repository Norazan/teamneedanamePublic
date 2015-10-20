//
// Created by martijn on 9/29/15.
//

#include "Camera.hpp"

Camera::Camera(sf::RenderWindow &window, Map &currentMap) :
	window{ window },
	currentMap{ currentMap }
{
}

void Camera::draw(){
	for (int i = currentMap.getLayers(); i >= 0; i--){
		for (auto mo : currentMap.getAllMapObjects()){
			if (mo->getRenderLayer() == i){
				mo->draw(window);
			}
		}
	}
}
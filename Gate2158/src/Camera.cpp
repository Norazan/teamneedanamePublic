//
// Created by martijn on 9/29/15.
//

#include "Camera.hpp"

//! Constructor of Camera
//
//! @parameter window for drawing the mapObjects on window
//! @parameter currenMap for drawing the correctly map
Camera::Camera(sf::RenderWindow &window, Map &currentMap) :
	window{ window },
	currentMap{ currentMap }
{
}

//! Draw function
//
//! Drawed all the MapObjects 
void Camera::draw(){
	for (int i = currentMap.getLayers(); i >= 0; i--){
		for (auto mo : currentMap.getAllMapObjects()){
			if (mo->getRenderLayer() == i){
				mo->draw(window);
			}
		}
	}
}
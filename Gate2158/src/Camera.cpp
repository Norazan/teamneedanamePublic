//
// Created by martijn on 9/29/15.
//

#include "Camera.hpp"
#include "Collision.h"
#include "MapObject.h"
#include <SFML/Graphics.hpp>

Camera::Camera(sf::RenderWindow &window, Map &currentMap, MapObject *player) :
	window{ window },
	currentMap{ currentMap },
	currentPlayer{ player }
{
}

void Camera::draw(){
	sf::Vector2f drawPosition;
	sf::Vector2f cameraBeginPosition;
	//int playerOutsideCameraLengthX, playerOutsideCameraLengthY;
	cameraBeginPosition.x = currentPlayer->getPosition().x - ((float)window.getSize().x / 2);
	cameraBeginPosition.y = currentPlayer->getPosition().y - ((float)window.getSize().y / 2);
	checkCollision();
	for (int i = currentMap.getLayers(); i >= 0; i--){
		for (auto mo : *getObjectsAroundPlayer()){
			drawPosition.x = mo->getPosition().x - cameraBeginPosition.x;
			drawPosition.y = mo->getPosition().y - cameraBeginPosition.y;
			if (mo->getRenderLayer() == i){
				mo->draw(window, drawPosition);
			}
		}
	}
}

std::vector<MapObject*> *Camera::getObjectsAroundPlayer(){
	sf::Vector2f regionX;
	sf::Vector2f regionY;
	regionX.x = currentPlayer->getPosition().x - ((float)window.getSize().x / 2 + 100);
	regionX.y = currentPlayer->getPosition().y - ((float)window.getSize().y / 2 + 100);
	regionY.x = currentPlayer->getPosition().x + ((float)window.getSize().x / 2 + 100);
	regionY.y = currentPlayer->getPosition().y + ((float)window.getSize().y / 2 + 100);
	return currentMap.getMapObjectsInRegion(regionX, regionY);
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
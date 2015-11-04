//
// Created by martijn on 9/29/15.
//

#include "Camera.hpp"
#include "Collision.h"
#include <iostream>
#include "MapObject.h"
#include <SFML/Graphics.hpp>

Camera * Camera::camera = NULL;

Camera::Camera(){
	//Do init
}

Camera * Camera::getInstance(){
	if (camera == NULL){
		camera = new Camera();
	}
	return camera;
}

void Camera::draw(){
	sf::Vector2f drawPosition;
	sf::Vector2f cameraBeginPosition;
	float oldRotation = 0, newRotation = 0;
	//int playerOutsideCameraLengthX, playerOutsideCameraLengthY;
	cameraBeginPosition.x = currentPlayer->getPosition().x - ((float)window->getSize().x / 2);
	cameraBeginPosition.y = currentPlayer->getPosition().y - ((float)window->getSize().y / 2);
	checkCollision();
	for (int i = currentMap->getLayers(); i >= 0; i--){
		for (auto &mo : *getObjectsAroundPlayer()){
			if (mo->getRenderLayer() == i){
				drawPosition.x = mo->getPosition().x - cameraBeginPosition.x;
				drawPosition.y = mo->getPosition().y - cameraBeginPosition.y;
				mo->setDrawPosition(drawPosition);
				mo->draw(*window, drawPosition);
				if (mo->getRenderLayer() == 2){
					mo->rotate(oldRotation);
					newRotation = mo->getRotation();
					oldRotation = newRotation;
				}
				mo->act(*window);
			}
		}
	}
	currentMap->removeMapObject(removeObjects);
	removeObjects.clear();
	for (auto & addObject : addObjects){
		currentMap->addMapObject(addObject);
	}
	addObjects.clear();
}

void Camera::addMapObjectToCurrentMap(MapObject *mo){
	addObjects.push_back(mo);
}

void Camera::revmoveMapObjectOnCurrentMap(MapObject *mo){
	removeObjects.push_back(mo);
}

std::vector<MapObject*> *Camera::getObjectsAroundPlayer(){
	sf::Vector2f regionX;
	sf::Vector2f regionY;
	regionX.x = currentPlayer->getPosition().x - ((float)window->getSize().x / 2 + 100);
	regionX.y = currentPlayer->getPosition().y - ((float)window->getSize().y / 2 + 100);
	regionY.x = currentPlayer->getPosition().x + ((float)window->getSize().x / 2 + 100);
	regionY.y = currentPlayer->getPosition().y + ((float)window->getSize().y / 2 + 100);
	return currentMap->getMapObjectsInRegion(regionX, regionY);
}

void Camera::checkCollision(){
	Collision collision;
	// get all playable objects
	for (auto &mo : currentMap->getAllMapObjects()){
		if (mo->getRenderLayer() < 3){
			// check if character has collision with objects
			for (auto &object : currentMap->getAllMapObjects()){
				if (object != mo){
					// do nothing with overlap
					(void)collision.checkCollision(*mo, *object);
				}
			}
		}
	}
}

void Camera::setWindow(sf::RenderWindow &window){
	this->window = &window;
}
void Camera::setCurrentMap(Map & currentMap){
	this->currentMap = &currentMap;
}
void Camera::setCurrentPlayer(MapObject *currentUser){
	this->currentPlayer = currentUser;
}
//
// Created by martijn on 9/28/15.
//

#include "MapObject.h"
#include <iostream>

MapObject::MapObject(){
	
}

MapObject::MapObject(int renderLayer, drawable* drawable) :
	renderLayer{ renderLayer },
	drawObject{drawable}
{

}

MapObject::MapObject(int renderLayer) :
	renderLayer{ renderLayer }
{

}

void MapObject::rotate(float rotation) {
	if (drawObject != nullptr){
		drawObject->setRotation(rotation);
	}
}

float MapObject::getRotation() {
	if (drawObject != nullptr){
		return drawObject->getRotation();
	}
	else {
		return 0;
	}
}


void MapObject::setPosition(sf::Vector2f pos){
	if (drawObject != nullptr){
		drawObject->setPosition(pos);
	}
}

sf::Vector2f MapObject::getPosition(){
	if (drawObject != nullptr){
		return drawObject->getPosition();
	}
	else {
		return sf::Vector2f{ 0, 0 };
	}
}

void MapObject::setRenderLayer(int renderLayer){
	this->renderLayer = renderLayer;
}

int MapObject::getRenderLayer(){
	return renderLayer;
}
void MapObject::draw(sf::RenderWindow & window){
	drawObject->draw(window);
}
sf::Vector2f MapObject::getSize(){
	if (drawObject != nullptr){
		return drawObject->getSize();
	}
	else {
		return sf::Vector2f{ 0, 0 };
	}
}
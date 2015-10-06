//
// Created by martijn on 9/28/15.
//

#include "MapObject.h"
#include <iostream>

MapObject::MapObject(){
	
}

MapObject::MapObject(int renderLayer, drawable *drawable):
	renderLayer{renderLayer},
	drawObject{ drawable }
{

}

void MapObject::rotate(float rotation) {
	drawObject->rotate(rotation);
}

float MapObject::getAngle() {
	return drawObject->getAngle();
}


void MapObject::setPosition(sf::Vector2f pos){
	drawObject->setPosition(pos);
}

sf::Vector2f MapObject::getPosition(){
	return drawObject->getPosition();
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
	return drawObject->getSize();
}
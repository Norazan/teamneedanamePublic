//
// Created by martijn on 9/28/15.
//

#include "MapObject.h"

MapObject::MapObject(){
	
}

MapObject::MapObject(int renderLayer, drawable *drawable):
	renderLayer{renderLayer},
	drawObject{ drawable }
{

}

void MapObject::setAngle(float angle) {
	this->angle = angle;
}

float MapObject::getAngle() {
    return angle;
}


void MapObject::setPosition(sf::Vector2f pos){
	position = pos;
}

sf::Vector2f MapObject::getPosition(){
	return position;
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
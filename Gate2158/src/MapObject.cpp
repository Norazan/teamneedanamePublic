//
// Created by martijn on 9/28/15.
//

#include "MapObject.h"



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
void MapObject::draw(){

}
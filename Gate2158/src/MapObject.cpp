//
// Created by martijn on 9/28/15.
//

#include "MapObject.h"
#include <iostream>

MapObject::MapObject(){
	
}

MapObject::MapObject(int renderLayer, drawable* drawable) :
	renderLayer{ renderLayer },
	drawObject{ drawable }
{
	
}

MapObject::MapObject(int renderLayer, drawable* drawable, Convex * hitbox) :
	renderLayer{ renderLayer },
	drawObject{ drawable },
	Hitbox{hitbox}
{

}

void MapObject::rotate(float rotation) {
	if (Hitbox != nullptr){
		Hitbox->setRotation(rotation);
	}
	drawObject->setRotation(rotation);
}

float MapObject::getRotation() {
	return drawObject->getRotation();
}


void MapObject::setPosition(sf::Vector2f pos){
	if (Hitbox != nullptr){
		Hitbox->setPosition(pos);
	}
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

std::vector<sf::Vector2f> MapObject::getConvexPoints(){
	return Hitbox->getPoints();
}

void MapObject::draw(sf::RenderWindow & window){
	if (Hitbox != nullptr){
		Hitbox->draw(window);
	}
	drawObject->draw(window);
}
sf::Vector2f MapObject::getSize(){
	return drawObject->getSize();
}

void MapObject::setHitbox(Convex * Hitbox){
	MapObject::Hitbox = Hitbox;
}

Convex* MapObject::getHitbox(){
	return Hitbox;
}
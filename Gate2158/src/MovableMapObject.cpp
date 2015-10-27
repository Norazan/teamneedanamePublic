//
// Created by martijn on 9/28/15.
//

#include "MovableMapObject.h"

MovableMapObject::MovableMapObject(int renderLayer, drawable* drawable, Convex *convex) :
	MapObject(renderLayer, drawable, convex)
{

}

void MovableMapObject::setVelocity(float v) {
    velocity = v;
}

float MovableMapObject::getVelocity() {
    return velocity;
}


void MovableMapObject::draw(sf::RenderWindow & window){

}


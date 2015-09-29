//
// Created by martijn on 9/28/15.
//

#include "MovableMapObject.h"

MovableMapObject::MovableMapObject() :
	MapObject()
{

}

void MovableMapObject::setVelocity(float v) {
    velocity = v;
}

float MovableMapObject::getVelocity() {
    return velocity;
}


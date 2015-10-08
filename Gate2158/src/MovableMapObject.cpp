//
// Created by martijn on 9/28/15.
//

#include "MovableMapObject.h"

MovableMapObject::MovableMapObject(int renderLayer, drawable* drawable) :
	MapObject(renderLayer, drawable)
{

}

void MovableMapObject::setVelocity(float v) {
    velocity = v;
}

float MovableMapObject::getVelocity() {
    return velocity;
}


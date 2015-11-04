//
// Created by martijn on 9/28/15.
//

#include "MovableMapObject.h"

MovableMapObject::MovableMapObject(int renderLayer, drawable* drawable, sf::Vector2f position, Convex *convex) :
	MapObject(renderLayer, drawable, position, convex)
{

}

void MovableMapObject::setVelocity(sf::Vector2f v) {
    velocity = v;
}

sf::Vector2f MovableMapObject::getVelocity() {
    return velocity;
}


void MovableMapObject::draw(sf::RenderWindow & window, sf::Vector2f drawPosition){

}

void MovableMapObject::collisionDetected(MapObject & mo){

}

void MovableMapObject::act(sf::RenderWindow & window){

}

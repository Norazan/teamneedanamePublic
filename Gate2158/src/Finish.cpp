//
// Created by Ole on 6/11/15.
//

#include "Finish.h"
#include "Camera.hpp"

Finish::Finish(int renderLayer, drawable* drawable, sf::Vector2f position, Convex * hitbox):
	MapObject{renderLayer, drawable, position, hitbox}
{

}
void Finish::draw(sf::RenderWindow &window, sf::Vector2f drawPosition){
	MapObject::draw(window, drawPosition);
}
void Finish::collisionDetected(MapObject &mo){
	if (mo.isFriend() == 1){
		Camera *camera = Camera::getInstance();
		camera->nextLevel = true;
	}
}
/**
* @file HealthPotion.h
* @author Ole
* @date 11//8/2015
* @version 1.0
*
* 
*/

#include "HealthPotion.h"
#include "Camera.hpp"

HealthPotion::HealthPotion(int renderLayer, drawable* drawable, sf::Vector2f position, Convex * hitbox) :
	MapObject{ renderLayer, drawable, position, hitbox }
{
	
}
void HealthPotion::draw(sf::RenderWindow &window, sf::Vector2f drawPosition){
	if (pickedUp){
		Camera *c = Camera::getInstance();
		c->revmoveMapObjectOnCurrentMap(this);
	}
	MapObject::draw(window, drawPosition);
}
void HealthPotion::collisionDetected(MapObject &mo){
	if (mo.isFriend() == 1){
		mo.setMaxHealth();
		pickedUp = true;
	}
}
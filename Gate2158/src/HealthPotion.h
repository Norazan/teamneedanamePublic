/**
* @file HealthPotion.h
* @author Ole
* @date 11//8/2015
* @version 1.0
*
*
*/

#include "MapObject.h"

#ifndef GATE2158_HEALTHPOTION_H
#define GATE2158_HEALTHPOTION_H

class HealthPotion : public MapObject {
public:
	HealthPotion(int renderLayer, drawable* drawable, sf::Vector2f position, Convex * hitbox);
	void draw(sf::RenderWindow &window, sf::Vector2f drawPosition);
	void collisionDetected(MapObject &mo) override;
private:
	bool pickedUp = false;
};


#endif
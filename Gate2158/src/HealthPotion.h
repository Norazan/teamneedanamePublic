/**
* @file HealthPotion.h
* @author Ole
* @date 11//8/2015
* @version 1.0
*
* The HealthPotion class to make healthpostions on the map
*/

#include "MapObject.h"

#ifndef GATE2158_HEALTHPOTION_H
#define GATE2158_HEALTHPOTION_H

class HealthPotion : public MapObject {
public:
	/**
	* Constructor that sets the variable of the HealthPotion.
	*
	* @param renderLayer
	*		The layer on where the health postion will be drawed
	* @param drawable
	*		The drawable that will be drawed
	* @param position
	*		The position on the map
	* @param convex
	*		The hitbox of the health postion
	*/
	HealthPotion(int renderLayer, drawable* drawable, sf::Vector2f position, Convex * hitbox);
	/**
	* Draws the Health Potion on the screen, and destroyed himself if pickedUp is true
	*
	* @param window
	*		The window where the healt potion will be drawed
	* @param drawPosition
	*		The position on the screen where the healt potion will be drawed
	*/
	void draw(sf::RenderWindow &window, sf::Vector2f drawPosition);
	/**
	* Set health of the player to his max health, and sets pickUp to true
	*
	* @param mo
	*		The MapObject where the health potion has collide with.
	*/
	void collisionDetected(MapObject &mo) override;
private:
	/**
	* Boolean pickedUp is used to remove the healt potion of the map
	*/
	bool pickedUp = false;
};


#endif
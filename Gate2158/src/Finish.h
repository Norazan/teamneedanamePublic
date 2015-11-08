/**
* @file Finish.h
* @author Ole
* @date 6/11/15
* @version 1.0
*
* The Finish class to make the finish on the map
*/

#include "MapObject.h"

#ifndef GATE2158_FINISH_H
#define GATE2158_FINISH_H

class Finish : public MapObject {
public:
	/**
	* Constructor that sets the variable of the Finish.
	*
	* @param renderLayer
	*		The layer on where the finish will be drawed
	* @param drawable
	*		The drawable that will be drawed
	* @param position
	*		The position on the map
	* @param convex
	*		The hitbox of the finish
	*/
	Finish(int renderLayer, drawable* drawable, sf::Vector2f position, Convex * hitbox);
	/**
	* Draws the finish on the screen
	*
	* @param window
	*		The window where the finish will be drawed
	* @param drawPosition
	*		The position on the screen where the finish will be drawed
	*/
	void draw(sf::RenderWindow &window, sf::Vector2f drawPosition);
	/**
	* Set nextLevel in camera to true if the player caused the collision
	*
	* @param mo
	*		The MapObject where the finish has collide with.
	*/
	void collisionDetected(MapObject &mo) override;
};

#endif
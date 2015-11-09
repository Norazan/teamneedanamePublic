/**
* @file MovableMapObject.h
* @author Martijn
* @date 9/28/15
* @version 1.0
*
* The MovableMapObject class to make MapObject that can move
*/

#ifndef GATE2158_MOVABLEMAPOBJECT_H
#define GATE2158_MOVABLEMAPOBJECT_H

#include "MapObject.h"
#include <SFML/Graphics.hpp>

class MovableMapObject : public MapObject {
public:
	/**
	* Constructor that sets the variable of the MovableMapObject.
	*
	* @param renderLayer
	*		The layer on where the MapObject will be drawed
	* @param drawable
	*		The drawable that will be drawed
	* @param position
	*		The position on the map
	* @param convex
	*		The hitbox of the MapObject
	*/
	MovableMapObject(int renderLayer, drawable* drawable, sf::Vector2f position, Convex* convex);
	/**
	* Sets the velocity
	*
	* @param v
	*		The velocity that will be set
	*/
	void setVelocity(sf::Vector2f v);
	/**
	* returns the velocity
	*
	* @return
	*		The velocity
	*/
    sf::Vector2f getVelocity();
	/**
	* Draws the MovableMapObject on the screen
	*
	* @param window
	*		The window where the MovableMapObject will be drawed
	* @param drawPosition
	*		The position on the screen where the MovableMapObject will be drawed
	*/
	virtual void draw(sf::RenderWindow & window, sf::Vector2f drawPosition) override;
	/**
	* What to do when a MovableMapObject collide is described in the other classes
	*
	* @param mo
	*		The MapObject where the MovableMapObject has collide with.
	*/
	virtual void collisionDetected(MapObject & mo) override;
	/**
	* All the activities that the MovableMapObject will do before drawing
	*
	* @param window
	*		The window where the activities take place
	*/
	virtual void act(sf::RenderWindow & window) override;
	/**
	* Returns the expoints based on how much damage is done (only useful on characters)
	*
	* @param damage
	*		The damage to calculate how much expoints are earned
	* @return
	*		The earned expoints
	*/
	virtual int getExpoints(int damage) override;
	/**
	* Sets damage to the MovableMapObject (only useful on characters)
	*
	* @param damage
	*		The damage
	*/
	virtual void setDamage(int damage) override;
	/**
	* Sets the maximum health of the MovableMapObject (only useful on characters)
	*/
	virtual void setMaxHealth() override;
private:
    sf::Vector2f velocity;	/** The velocity of the MovableMapObject */
};


#endif //GATE2158_MOVABLEMAPOBJECT_H

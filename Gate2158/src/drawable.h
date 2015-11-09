/**
* @file drawable.h
* @author -
* @date -
* @version 1.0
*
* The drawable is a abstract class that can be used to draw a shape.
*/

#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include <SFML/Graphics.hpp>

class drawable {
public:
	/**
	* Draws a object on the screen
	*
	* @param window
	*		The window where the object will be drawed
	* @param drawPosition
	*		The position on the screen where the object will be drawed
	*/
	virtual void draw(sf::RenderWindow &window, sf::Vector2f &pos) = 0;
	/**
	* Returns the size of the ojbect
	*
	* @return
	*		The size of the object
	*/
	virtual sf::Vector2f getSize() = 0;
	/**
	* Returns the rotation of the object
	*
	* @return
	*		The rotation of the ojbect
	*/
	virtual float getRotation() = 0;
	/**
	* Sets the rotation of the object
	*
	* @param rotation
	*		The rotation that will be set
	*/
	virtual void setRotation(float rotation) = 0;
};

#endif
/**
* @file Circle.h
* @author Ole
* @date 10/6/15
* @version 1.0
*
* The Circle class to draw a circle shape.
*/

#ifndef GATE2158_CIRCLE_H
#define GATE2158_CIRCLE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Circle : public drawable {
public:
	/**
	* Constructor that sets the variable of the Circle and sets the origin to the center.
	*
	* @param radius
	*		The radius of the circle
	* @param color
	*		The color of the circle
	*/
	Circle(float radius, sf::Color color);
	/**
	* Draws the circle on the screen
	*
	* @param window
	*		The window where the circle will be drawed
	* @param drawPosition
	*		The position on the screen where the circle will be drawed
	*/
	void draw(sf::RenderWindow &window, sf::Vector2f position);
	/**
	* Returns the size of the circle
	*
	* @return
	*		The size of the circle
	*/
	sf::Vector2f getSize() override;
	/**
	* Returns the rotation of the circle
	*
	* @return
	*		The rotation of the circle
	*/
	float getRotation() override;
	/**
	* Sets the rotation of the circle
	*
	* @param rotation
	*		The rotation that will be set
	*/
	void setRotation(float rotation) override;
private:
	/**
	* The sf::CircleShape that will be used to draw the circle
	*/
	sf::CircleShape circle;
};

#endif //GATE2158_CIRCLE_H
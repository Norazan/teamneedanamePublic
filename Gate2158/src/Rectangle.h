/**
* @file Rectangle.h
* @author Ole
* @date 10/1/15
* @version 1.0
*
* The Rectangle class to draw a rectangle shape.
*/

#ifndef GATE2158_RECTANGLE_H
#define GATE2158_RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

/**
 * @brief A drawable class used to draw a rectangle on the screen
 * 
 */
class Rectangle : public drawable {
public:
	/**
	* Constructor that sets the variable of the Rectangle and sets the origin to the center.
	*
	* @param size
	*		The size of the rectangle
	* @param color
	*		The color of the rectangle
	*/
	Rectangle(sf::Vector2f size, sf::Color color);
	/**
	* Draws the rectangle on the screen
	*
	* @param window
	*		The window where the rectangle will be drawed
	* @param position
	*		The position on the screen where the rectangle will be drawed
	*/
	void draw(sf::RenderWindow &window, sf::Vector2f &position) override;
	/**
	* Returns the size of the rectangle
	*
	* @return
	*		The size of the rectangle
	*/
	sf::Vector2f getSize() override;
	/**
	* Returns the rotation of the rectangle
	*
	* @return
	*		The rotation of the rectangle
	*/
	float getRotation() override;
	/**
	* Sets the rotation of the rectangle
	*
	* @param rotation
	*		The rotation that will be set
	*/
	void setRotation(float rotation) override;
private:
	sf::RectangleShape rectangle;			/** The sf::RectangleShape that will be used to draw the rectangle */
};

#endif //GATE2158_RECTANGLE_H
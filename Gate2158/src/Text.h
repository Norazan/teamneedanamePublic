/**
* @file Text.h
* @author Ole
* @date 10/3/15
* @version 1.0
*
* The Text class to draw a text on the screen.
*/

#ifndef GATE2158_TEXT_H
#define GATE2158_TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.h"

class Text : public drawable {
public:
	/**
	* Constructor that sets the variable of the Text.
	*
	* @param t
	*		The text that will be drawed
	* @param pos
	*		The postition where the text will be drawed
	* @param style
	*		The style of the text
	* @param color
	*		The color of the text
	* @param size
	*		The size of the text
	* @param font
	*		The font of the text
	*/
	Text(
		std::string t,
		sf::Vector2f pos,
		sf::Text::Style style,
		sf::Color color,
		int size,
		sf::Font *font
	);
	/**
	* Returns the size of the text
	*
	* @return
	*		The size of the text
	*/
	sf::Vector2f getSize() override;
	/**
	* Returns the rotation of the text
	*
	* @return
	*		The rotation of the text
	*/
	float getRotation() override;
	/**
	* Sets the rotation of the text
	*
	* @param rotation
	*		The rotation that will be set
	*/
	void setRotation(float rotation) override;
	/**
	* Draws the text on the screen
	*
	* @param window
	*		The window where the text will be drawed
	* @param postion
	*		The position on the screen where the text will be drawed
	*/
	void draw(sf::RenderWindow &window, sf::Vector2f &position);
	/**
	* Sets a new text
	*/
	void setText(std::string s);

private:
	sf::Text text;		/** The sf::Text that will be used to draw the text */
};

#endif //GATE2158_TEXT_H
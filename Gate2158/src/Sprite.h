/**
* @file Sprite.h
* @author Ole
* @date 10/2/15
* @version 1.0
*
* The Sprite class to draw a sprite.
*/

#ifndef GATE2158_SPRTIE_H
#define GATE2158_SPRITE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Sprite : public drawable {
public:
	/**
	* Constructor that sets the variable of the Sprite and sets the origin to the center.
	*
	* @param name
	*		The path to the image
	*/
	Sprite(std::string name);
	/**
	* Draws the sprtie on the screen
	*
	* @param window
	*		The window where the sprite will be drawed
	* @param postion
	*		The position on the screen where the sprite will be drawed
	*/
	void draw(sf::RenderWindow &window, sf::Vector2f &position);
	/**
	* Returns the size of the sprite
	*
	* @return
	*		The size of the sprite
	*/
	sf::Vector2f getSize() override;
	/**
	* Returns the rotation of the sprite
	*
	* @return
	*		The rotation of the sprite
	*/
	float getRotation() override;
	/**
	* Sets the rotation of the sprite
	*
	* @param rotation
	*		The rotation that will be set
	*/
	void setRotation(float rotation) override;
private:
	sf::Texture texture;		/** The texture that will be used to make the sprite */
	sf::Sprite sprite;			/** The sf::Sprite that will be used to draw the sprite */
};

#endif //GATE2158_SPRITE_H
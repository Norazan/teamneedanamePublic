/**
* @file Collision.h
* @author Jordan
* @date 10/26/15
* @version 1.0
*
* The Convex class is used to make a hitbox, or just a convex.
*/

#ifndef GATE2158_CONVEX_H
#define GATE2158_CONVEX_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "drawable.h"

class Convex : public drawable {
public:
	/**
	* Constructor set the points of the convex, used for making a white convexShape
	*
	* @param points
	*		The points of the convex
	*/
	Convex(std::vector<sf::Vector2f> points);
	/**
	* Constructor set the points of the convex, used for making a transparant convexShape.
	* It also sets the origin to the center of the convex.
	*
	* @param points
	*		The points of the convex
	* @param center
	*		The center of the convex
	*/
	Convex(std::vector<sf::Vector2f> points, sf::Vector2f center);
	/**
	* Draws the convex on the screen
	*
	* @param window
	*		The window where the circle will be drawed
	* @param position
	*		The position on the screen where the circle will be drawed
	*/
	void draw(sf::RenderWindow &window, sf::Vector2f &position);
	/**
	* Returns the rotation of the convex
	*
	* @return
	*		The rotation of the convex
	*/
	float getRotation() override;
	/**
	* Sets the rotation of the convex
	*
	* @param rotation
	*		The rotation that will be set
	*/
	void setRotation(float rotation) override;
	/**
	* Returns the size of the convex
	*
	* @return
	*		The size of the convex
	*/
	sf::Vector2f getSize() override;
	/**
	* Returns the points of the convex without rotation,
	* because SFML don't returns the rotated points.
	*
	* @return
	*		The points of the convex
	*/
	std::vector<sf::Vector2f>& getPoints();
	/**
	* Returns the origin of the convex
	*
	* @return
	*		The center of the convex
	*/
	sf::Vector2f getOrigin();
private:
	/**
	* The sf::ConvexShape that will be used to draw the convex
	*/
	sf::ConvexShape convex;
	/**
	* The points of the convex, without rotation
	*/
	std::vector<sf::Vector2f> points;
};

#endif GATE2158_CONVEX_H

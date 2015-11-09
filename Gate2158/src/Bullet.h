/**
* @file Bullet.h
* @author  
* @version 1.0
*
* The Bullet class represents a bullet on the screen.
*/

#ifndef GATE2158_BULLET_H
#define GATE2158_BULLET_H

#include "Camera.hpp"
#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Weapon.h"
class Camera;
class Bullet : public MapObject {
public:
	/**
	* Constructor that sets the variable of the bullet.
	*
	* @param bulletDamage 
	*		The damage of the bullet
	* @param startingLocation 
	*		The location on the map
	* @param startingVelocity 
	*		The velocity of the bullet
	* @param drawLoctation 
	*		The location where the bullet has to be drawed
	* @param angle 
	*		The angle of the bullet in degrees
	* @param weapon 
	*		The weapon that shoots the bullet
	* @param isFriend
	*		A number that shows which character has shot, so it does not collide 	
	* @param gunTexture
	*		The texture of the bullet
	*/
	Bullet(
		int bulletDamage,
		sf::Vector2f startingLocation,
		sf::Vector2f startingVelocity,
		sf::Vector2f drawLoctation,
		float angle,
		Weapon* weapon,
		int isFriend,
		sf::Texture & gunTexture
	);
	/**
	* Draws the bullet on the screen
	*
	* @param window
	*		The window where the bullet will draw
	* @param drawPosition
	*		The position on the screen where the bullet will draw
	*/
	void draw(sf::RenderWindow & window, sf::Vector2f drawPosition) override;
	/**
	* Checked of the bullet out of bounds is
	* 
	* @param window
	*		The window where the check takes place
	* @return 
	*		Boolean if bullet is out of bounds
	*/
	bool outOfBound(sf::RenderWindow & window);
	/**
	* Destroyed the bullet, sets the damage on param and sets the expoints on the weapon
	*
	* @param mo
	*		The MapObject where the bullet has collide with.
	*/
	void collisionDetected(MapObject &mo) override;
private:
	/**
	* the shape of the bullet
	*/
	sf::CircleShape bullet;
	/**
	* The weapon that shoots the bullet, for giving expoints
	*/
	Weapon* weapon;
	/**
	* The damage of the bullet
	*/
	int damage;
	/**
	* The location on the map
	*/
	sf::Vector2f location;
	/**
	* The velocity of the bullet
	*/
	sf::Vector2f velocity;
	/**
	* The speed of the bullet
	*/
	float bSpeed = 10;
	/**
	* The angle of the bullet
	*/
	float angle = 0;
	/**
	* Boolean if bullet has collide
	*/
	bool hasCollision = false;
	/** 
	* The Camera to remove the bullet of the screen
	*/
	Camera* c;
};

#endif
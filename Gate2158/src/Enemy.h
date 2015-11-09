/**
* @file Enemy.h
* @author Ole
* @date -
* @version 1.0
*
* The Enemy class to make a enemy.
*/

#ifndef GATE2158_ENEMY_H
#define GATE2158_ENEMY_H

#include "Character.h"
#include "Camera.hpp"
#include "ProjectileWeapon.h"

#define PI 3.14159265
#define angleOfAbove 270.0;
#define angleOfUnder 90.0;
#define angleOfLeft 180.0;
#define angleOfRight 0.0;

class ProjectileWeapon;

class Enemy : public Character {
public:
	/**
	* Constructor that sets the variable of the Enemy.
	*
	* @param position
	*		The position of the enemy on the map
	* @param user
	*		The user (player) of the game, used to calculate where to shoot
	* @param weapon
	*		The weapon of the enemy
	* @param health
	*		The health of the enemy
	* @param renderLayer
	*		The layer where the enemy will be drawed
	* @param convex
	*		The Hitbox for checking the collision
	* @param drawable
	*		The drawable for drawing the enemy on the screen
	*/
	Enemy(
		sf::Vector2f position, 
		MapObject *user, 
		std::string weapon, 
		float health, 
		int renderLayer, 
		Convex* convex, 
		drawable* drawable
	);
	/**
	* Draws the enemy on the screen
	*
	* @param window
	*		The window where the enemy will be drawed
	* @param drawPosition
	*		The position on the screen where the enemy will be drawed
	*/
	void draw(sf::RenderWindow & window, sf::Vector2f drawPosition) override;
	/**
	* Sets the enemy back on the place where there was no collision
	* And stops the rotation, so the enemy can't rotate in to the object.
	*
	* @param mo
	*		The MapObject where the enemy has collide with.
	*/
	void collisionDetected(MapObject & mo) override;
	/**
	* The enemy will aim and shoot to the player,
	* It calls the funtion walk() and it will check if the enemy is death.
	*
	* @param window
	*		The window where the activities take place
	*/
	void act(sf::RenderWindow & window) override;
	/**
	* Sets the damage on the enemy
	*
	* @param damage
	*		The number of damage the bullet has
	*/
	void setDamage(int damage) override;
	/**
	* Changed the velocity if the enemy is outside the window
	*/
	void walk();
private:
	/**
	* Adds the velocity to the position
	*
	* @param dir
	*		The velocity that will be added to the position
	*/
	void move(sf::Vector2f dir);
	/**
	* Calculates the rotation
	*
	* @param userPosition
	*		The position of the player where the enemy will rotate to
	* @return
	*		The rotation in degrees
	*/
	float calculateRotation(sf::Vector2f userPosition);
	/**
	* The weapon of the enemy
	*/
	ProjectileWeapon *weapon;
	/**
	* The player of the game
	*/
	MapObject *user;
	/**
	* The current rotation of the enemy in degrees
	*/
	float currentRotation;
	/**
	* The previous rotation of the enemy in degrees
	* Used to rotate back when the enemy collide with a object
	*/
	float previousRotation;
	/**
	* Boolean if the enemy can rotate
	* Used so the enemy can't rotate when it collide with a object
	*/
	bool canRotate = true;
};

#endif
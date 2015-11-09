/**
* @file Weapon.h
* @author -
* @date -
* @version 1.0
*
* The Weapon class used to make a Weapon.
*/

#ifndef GATE2158_WEAPON_H
#define GATE2158_WEAPON_H

#include <SFML/Graphics.hpp>
class Weapon{
public:
	/**
	* Used to shoot a bullet
	*
	* @param location
	*		The start location of the bullet
	* @param angle
	*		The angle of the bullet
	*/
	virtual void shoot(sf::Vector2f location, float angle) = 0;
	/**
	* Returns the ammo
	*
	* @return
	*		The ammo
	*/
	virtual int getAmmo() = 0;
	/**
	* Sets the ammo
	*
	* @param ammo
	*		The ammo that will be set
	*/
	virtual void setAmmo(int ammo) = 0;
	/**
	* Calculates the damage of the bullet
	*
	* @return
	*		The damage
	*/
	virtual int calculateDamage()= 0;
	/**
	* Sets the expoints of the current gun, and checked if the gun has leveled.
	*
	* @param expoints
	*		The expoints that will be set
	*/
	virtual void setExpoints(int expoints) = 0;
};


#endif
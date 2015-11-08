/**
* @file Character.h
* @author Martijn
* @date 9/28/15
* @version 1.0
*
* The Character class to make characters
*/

#ifndef GATE2158_CHARACTER_H
#define GATE2158_CHARACTER_H


#include "MovableMapObject.h"

class Character : public MovableMapObject {
public:
	/**
	* Constructor that sets the variable of the character.
	*
	* @param maxHealth
	*		The maximum health of the character
	* @param renderLayer
	*		The layer on where the character will be drawed
	* @param drawable
	*		The drawable that will be drawed
	* @param position
	*		The position on the map
	* @param convex
	*		The hitbox of the character
	*/
	Character(float maxHealth, int renderLayer, drawable* drawable, sf::Vector2f position, Convex* convex);
	/**
	* Draws the character on the screen
	*
	* @param window
	*		The window where the character will be drawed
	* @param drawPosition
	*		The position on the screen where the character will be drawed
	*/
	virtual void draw(sf::RenderWindow & window, sf::Vector2f drawPosition) override;
	/**
	* All the activities that the character will do before drawing
	*
	* @param window
	*		The window where the activities take place
	*/
	virtual void act(sf::RenderWindow & window) override;
	/**
	* Calculate what the expoints are when character is hit by a bullet
	*
	* @param damage
	*		The number of damage the bullet has, is used to calculate the expoints
	* @return
	*		The number of expoints
	*/
	virtual int getExpoints(int damage) override;
	/**
	* Sets the damage on the character
	*
	* @param damage
	*		The number of damage the bullet has
	*/
	virtual void setDamage(int damage) override;
	/**
	* Sets the health of the character to the max health
	*/
	void setMaxHealth() override;
protected:
	/**
	* Returns the health of the character
	*
	* @return 
	*		Health of character
	*/
    float getHealth(void);
	/**
	* Sets the health of the character
	*
	* @param h
	*		The number of health that will be set
	*/
    void setHealth(float h);
	/**
	* Changed the position of the character
	*
	* @param mo
	*		The MapObject where the character has collide with.
	*/
	virtual void collisionDetected(MapObject & mo) override;
	/**
	* The health of the character
	*/
    float health;
	/**
	* The maximum health of the character
	*/
    float maxHealth;
};


#endif //GATE2158_CHARACTER_H

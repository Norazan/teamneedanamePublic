/**
* @file UserCharacter.h
* @author Thijs
* @date 9/29/15
* @version 1.0
*
* The UserCharacter class to make a player.
*/

#ifndef GATE2158_USERCHARACTER_H
#define GATE2158_USERCHARACTER_H

#include "Character.h"
#include "UserInput.h"
#include "Text.h"
#include <SFML/Graphics.hpp>
#include "ProjectileWeapon.h"

#define PI 3.14159265
#define angleOfAbove 270.0;
#define angleOfUnder 90.0;
#define angleOfLeft 180.0;
#define angleOfRight 0.0;

struct text{
	Text t;
	std::string name;
	sf::Vector2f position;
};

class ProjectileWeapon;
class UserCharacter : public Character {
public:
	/**
	* Constructor that sets the variable of the Text.
	*
	* @param maxHealth
	*		The maximum health of the userCharacter
	* @param renderLayer
	*		The layer where the userCharacter will be drawed
	* @param drawable
	*		The drawable that will be drawed
	* @param position
	*		The position of the userCharacter
	* @param convex
	*		The hitbox of the userCharacter
	*/
	UserCharacter(float maxHealth, int renderLayer, drawable* drawable, sf::Vector2f position, Convex* convex);
	/**
	* Draws the userCharacter on the screen
	*
	* @param window
	*		The window where the userCharacter will be drawed
	* @param postion
	*		The position on the screen where the userCharacter will be drawed
	*/
	void draw(sf::RenderWindow & window, sf::Vector2f drawPosition) override;
	/**
	* Sets the UserCharacter back to its previous position and sets the boolean canRotate to false
	*
	* @param mo
	*		The MapObject where the userCharacter has collide with.
	*/
	void collisionDetected(MapObject & mo) override;
	/**
	* Drawed the userInput, (the health, ammo, ammoInMagazine, expoints and the tier).
	*
	* @param window
	*		The window where the userinput will be drawed.
	*/
	void drawUserInterface(sf::RenderWindow & window);
	/**
	* Calls the funtions processKeys and processMouse.
	*
	* @param window
	*		The window where the activities take place
	*/
	void act(sf::RenderWindow & window) override;
	/**
	* Sets the damage on the userCharacter
	*
	* @param damage
	*		The number of damage the bullet has
	*/
	void setDamage(int damage) override;
	/**
	* Returns a list of the expoints of the guns
	*
	* @return
	*		The a list of the expoints of the guns
	*/
	std::vector<int> getWeaponExpoints();
	/**
	* Sets all expoints of the guns.
	*
	* @param tiers
	*		A list of expoints of the guns
	*/
	void setWeaponExpoints(std::vector<int> tiers);

private:
	/**
	* Adds the velocity to the position
	*
	* @param dir
	*		The velocity that will be added to the position
	*/
	void move(sf::Vector2f dir);
	/**
	* Check of one of the keys is pressed.
	* And use function move to change the position of the character.
	*/
	void processKeys();
	/**
	* Checks where the mouse is, calls the function calculateRotation and sets the rotation.
	*
	* @param window
	*		The window to check where the mouse is
	*/
	void processMouse(sf::RenderWindow & window);
	/**
	* Calculate the rotation, so the character rotate to the mouse.
	*
	* @return
	*		The rotation in degrees
	*/
	float calculateRotation(sf::Vector2i mousePosition);
	/**
	* Makes the userInterface
	*/
	void makeUserInterface();

	UserInput input;					/** Input, to check the keys. */
	int speed = 10;						/** The speed of the character in pixels. */
	ProjectileWeapon* pistol;			/** The weapon of the userCharacter */
	float currentRotation;				/** The current rotation of the userCharacter in degrees */
	float previousRotation;				/** The previous rotation of the userCharacter in degrees */
	bool canRotate = true;				/** A boolean if the userCharacter can rotate */
	sf::Font tFont;						/** The font of the userInterface */
	std::vector<text> userInterface;	/** A list of texts for userInterface */
};

#endif //GATE2158_USERCHARACTER_H
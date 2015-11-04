//
// Created by Thijs on 9/29/15.
//

#ifndef GATE2158_USERCHARACTER_H
#define GATE2158_USERCHARACTER_H

#include "Character.h"
#include "UserInput.h"
#include "Text.h"
#include <SFML/Graphics.hpp>
#include "ProjectileWeapon.h"
#include "Camera.hpp"

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

class UserCharacter : public Character {
public:
	//! Constructor
	//
	//! @parameter maxHealth
	//! @parameter renderLayer
	//! @parameter drawable
	UserCharacter(float maxHealth, int renderLayer, drawable* drawable, sf::Vector2f position, Convex* convex);

	//! Function draw
	//
	//! draws the drawable of the UserCharacter.
	void draw(sf::RenderWindow & window) override;

	void setCamera(Camera * c); 
	void collisionDetected(MapObject & mo) override;

	void drawUserInterface(sf::RenderWindow & window);
	void act(sf::RenderWindow & window) override;

private:
	//! Function move
	//
	//! @parameter dir is de direction and speed of movement
	//! Adds the direction to the position.
	void move(sf::Vector2f dir);

	//! Funcion processKeys
	//
	//! Check of one of the keys is pressed.
	//! And use function move to change the position of the character.
	void processKeys();

	//! Function processMous
	//
	//! @parameter window
	//! Checks where the mouse is.
	//! Calls the function calculateRotation and sets the rotation.
	void processMouse(sf::RenderWindow & window);

	//! Function calculateRotation
	//
	//! @parameter mousePosition
	//! Calculate the rotation, so the character rotate to the mouse.
	//! And returns the value of the rotation.
	float calculateRotation(sf::Vector2i mousePosition);

	void makeUserInterface();

	//! input, to check the keys.
	UserInput input;

	//! the speed of the character in pixels.
	int speed = 10;

	ProjectileWeapon* pistol;
	//! the current rotation of the character in degrees.
	float currentRotation;
	
	//! the previous rotation of the character in degrees.
	float previousRotation;

	//! boolean canRotate
	bool canRotate = true;

	sf::Font tFont;

	std::vector<text> userInterface;
};

#endif //GATE2158_USERCHARACTER_H
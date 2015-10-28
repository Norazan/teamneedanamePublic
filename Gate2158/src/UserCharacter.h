//
// Created by Thijs on 9/29/15.
//

#ifndef GATE2158_USERCHARACTER_H
#define GATE2158_USERCHARACTER_H

#include "Character.h"
#include "UserInput.h"
#include <SFML/Graphics.hpp>
#include "ProjectileWeapon.h"

#define PI 3.14159265
#define angleOfAbove 270.0;
#define angleOfUnder 90.0;
#define angleOfLeft 180.0;
#define angleOfRight 0.0;

class UserCharacter : public Character {
public:
	//! Constructor
	//
	//! @parameter maxHealth
	//! @parameter renderLayer
	//! @parameter drawable
	UserCharacter(float maxHealth, int renderLayer, drawable* drawable);

	//! Function draw
	//
	//! draws the drawable of the UserCharacter.
	void draw(sf::RenderWindow & window) override;

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

	//! input, to check the keys.
	UserInput input;

	//! the speed of the character in pixels.
	int speed = 10;

	ProjectileWeapon* pistol;
};

#endif //GATE2158_USERCHARACTER_H
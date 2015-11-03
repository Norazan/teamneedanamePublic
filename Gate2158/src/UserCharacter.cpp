//
// Created by Thijs on 9/29/15.
//

#include "UserCharacter.h"
#include "UserInput.h"
#include "Collision.h"
#include "Text.h"
#include <cmath>
#include <math.h>
#include <iostream>

UserCharacter::UserCharacter(float maxHealth, int renderLayer, drawable* drawable, Convex* convex) :
	Character(maxHealth, renderLayer, drawable, convex)
{
	isFriendly = true;
	input.setToggleKey(sf::Keyboard::W);
	input.setToggleKey(sf::Keyboard::A);
	input.setToggleKey(sf::Keyboard::S);
	input.setToggleKey(sf::Keyboard::D);
	input.setToggleKey(sf::Keyboard::R);

	pistol = new ProjectileWeapon("pistol", isFriendly);

	if (!tFont.loadFromFile("../../Gate2158/media/Another_America.ttf")){
		//Error handeling
		std::cout << "can't load font";
	}
	makeUserInterface();
}

void UserCharacter::draw(sf::RenderWindow & window) {
	input.updateToggleKey();
	processKeys();
	processMouse(window);
	drawUserInterface(window);
	MapObject::draw(window);
}

void UserCharacter::setCamera(Camera * c){
	pistol->setCamera(c);
}

void UserCharacter::move(sf::Vector2f dir){
	setPosition(getPosition() + dir);
}

void UserCharacter::processKeys(){
	sf::Vector2f velocity{ 0.0, 0.0 };
	// check if key is hold and set velocity

	if (input.isKeyHold(sf::Keyboard::W)){
		velocity.y -= speed;
		canRotate = true;
	}
	if (input.isKeyHold(sf::Keyboard::A)){
		velocity.x -= speed;
		canRotate = true;
	}
	if (input.isKeyHold(sf::Keyboard::S)){
		velocity.y += speed;
		canRotate = true;
	}
	if (input.isKeyHold(sf::Keyboard::D)){
		velocity.x += speed;
		canRotate = true;
	}
	if (input.isKeyHold(sf::Keyboard::R)){
		pistol->reload();
	}
	// move userCharacter with the velocity that has been set.
	setVelocity(velocity);
	move(velocity);
}

void UserCharacter::processMouse(sf::RenderWindow & window){
	// Get mouse position, claculate the rotation and set the rotation.
	sf::Vector2i mousePosition = input.getMousePosition(window);
	if (canRotate){
		previousRotation = currentRotation;
		currentRotation = calculateRotation(mousePosition);
		rotate(currentRotation);
	}
	if (input.getMousePress(sf::Mouse::Button::Left)){
		pistol->shoot(getPosition(), calculateRotation(mousePosition));
	}
}

float UserCharacter::calculateRotation(sf::Vector2i mousePosition){
	sf::Vector2f pos = getPosition();
	// Make vector with the difference between the two vectors, position of character and position of the mouse.
	sf::Vector2f difference{ (pos.x - mousePosition.x), (pos.y - mousePosition.y) };

	// check of one of the cordinates of mouse the same is as the cordinates of position 
	if (difference.x == 0 && difference.y > 0){			// mouse is directly above character
		return angleOfAbove;
	}
	else if (difference.x == 0 && difference.y < 0){	// mouse is directly under character
		return angleOfUnder;
	}
	else if (difference.y == 0 && difference.x > 0){	// mouse is left of character
		return angleOfLeft;
	}
	else if (difference.y == 0 && difference.x < 0){	// mouse is right of character
		return angleOfRight;
	}


	// Make a copy of difference with absolute values.
	sf::Vector2f absoluteDifference{ std::abs(difference.x), std::abs(difference.y) };
	// calculate the angle relative to te y-as.
	float angle = (atan(absoluteDifference.x / absoluteDifference.y) * float(180)) / float(PI);

	// You have four places where the mouse can be relative to the character.
	// With the vector difference we can see in witch place the mouse is.
	// p1 = right top		difference = (negative x, positive y)
	// p2 = left top		difference = (positive x, positive y)
	// p3 = left under		difference = (positive x, negative y)
	// p4 = right under		difference = (negative x, negative y)

	// check in witch place the mouse is and calculate the rotation relative to rotation point 0.
	float rotation = 0;
	if (difference.x < 0 && difference.y > 0){			// p1
		rotation = 270 + angle;
	}
	else if (difference.x > 0 && difference.y > 0){		// p2
		rotation = 270 - angle;
	}
	else if (difference.x > 0 && difference.y < 0){		// p3
		rotation = 90 + angle;
	}
	else if (difference.x < 0 && difference.y < 0){		// p4
		rotation = 90 - angle;
	}
	return rotation;
}

void UserCharacter::collisionDetected(MapObject & mo){
	sf::Vector2f velocity = getVelocity();
	move(-velocity);
	canRotate = false;
	rotate(previousRotation);
	if (mo.isFriend()){
		move(velocity);
	}
}

void UserCharacter::makeUserInterface(){
	Text ammoInMagazine(
		std::to_string(pistol->getAmmoInMagazine()),
		sf::Vector2f(500, 50), 
		sf::Text::Style::Regular, 
		sf::Color::Red, 
		30, 
		&tFont
	);
	Text currentAmmo(
		std::to_string(pistol->getAmmo()),
		sf::Vector2f(550, 50),
		sf::Text::Style::Regular,
		sf::Color::Red,
		30,
		&tFont
	);
	std::cout << std::to_string(pistol->getAmmo());
	userInterface.push_back(ammoInMagazine);
	userInterface.push_back(currentAmmo);
}

void UserCharacter::drawUserInterface(sf::RenderWindow & window){
	for (auto & ui : userInterface){
		ui.draw(window);
	}
}

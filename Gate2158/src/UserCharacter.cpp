//
// Created by Thijs on 9/29/15.
//

#include "UserCharacter.h"
#include "UserInput.h"
#include <cmath>
#include <math.h>
#include <iostream>

UserCharacter::UserCharacter(float maxHealth, int renderLayer, drawable* drawable) :
	Character(maxHealth, renderLayer, drawable)
{
	input.setToggleKey(sf::Keyboard::W);
	input.setToggleKey(sf::Keyboard::A);
	input.setToggleKey(sf::Keyboard::S);
	input.setToggleKey(sf::Keyboard::D);
	weapon = new ProjectileWeapon(2, 10, 5, 100, 20, 10);
}

void UserCharacter::draw(sf::RenderWindow & window) {
	input.updateToggleKey();
	processKeys();
	processMouse(window);
	MapObject::draw(window);
}

void UserCharacter::move(sf::Vector2f dir){
	setPosition(getPosition() + dir);
}

void UserCharacter::processKeys(){
	sf::Vector2f velocity{ 0.0, 0.0 };
	// check if key is hold and set velocity
	if (input.isKeyHold(sf::Keyboard::W)){
		velocity.y -= speed;
	}
	if (input.isKeyHold(sf::Keyboard::A)){
		velocity.x -= speed;
	}
	if (input.isKeyHold(sf::Keyboard::S)){
		velocity.y += speed;
	}
	if (input.isKeyHold(sf::Keyboard::D)){
		velocity.x += speed;
	}
	// move userCharacter with the velocity that has been set.
	move(velocity);
}

void UserCharacter::processMouse(sf::RenderWindow & window){
	// Get mouse position, claculate the rotation and set the rotation.
	sf::Vector2i mousePosition = input.getMousePosition(window);
	rotate(calculateRotation(mousePosition));
	if (input.getMousePress(sf::Mouse::Button::Left)){
		weapon->shoot(getPosition(), calculateRotation(input.getMousePosition(window)));
	}
}

float UserCharacter::calculateRotation(sf::Vector2i mousePosition){
	sf::Vector2f pos = getPosition();
	std::cout << "ojbect = (" << pos.x << "," << pos.y << ")  mouse = (" << mousePosition.x << "," << mousePosition.y << ")\n";
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

//
// Created by Thijs on 9/29/15.
//

#include "UserCharacter.h"
#include "UserInput.h"

UserCharacter::UserCharacter(sf::Vector2f charSize, sf::Vector2f charInitPos, sf::Color charColor) :
	charSize(charSize),
	charInitPos(charInitPos),
	charColor(charColor)
{}

void UserCharacter::draw(sf::RenderWindow & window) const{
	character(charSize);
	character.setPosition(charInitPos);
	character.setFillColor(charColor);
	window.draw(character);
}

void UserCharacter::move(sf::Vector2f dir) const{
	character.setPosition(character.getPosition() + dir);
}
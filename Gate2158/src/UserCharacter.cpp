//
// Created by Thijs on 9/29/15.
//

#include "UserCharacter.h"
#include "UserInput.h"

UserCharacter::UserCharacter(float maxHealth, int renderLayer, drawable* drawable) :
Character(maxHealth, renderLayer, drawable)

{}

void UserCharacter::draw(sf::RenderWindow & window) {
	MapObject::draw(window);
}

void UserCharacter::move(sf::Vector2f dir){
	setPosition(getPosition() + dir);
}
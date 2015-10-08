//
// Created by martijn on 9/28/15.
//

#include "Character.h"

Character::Character(float maxHealth, int renderLayer, drawable* drawable) :
	MovableMapObject(renderLayer, drawable),
	maxHealth{maxHealth}
{

}

void Character::draw(sf::RenderWindow & window){
	MapObject::draw(window);
}

float Character::getHealth(void) {
	return 0;
}

void Character::setHealth(float h) {
    health = h;
}

//
// Created by martijn on 9/28/15.
//

#include "Character.h"
#include <iostream>

Character::Character(float maxHealth, int renderLayer, drawable* drawable, sf::Vector2f position, Convex* convex) :
	MovableMapObject(renderLayer, drawable, position, convex),
	maxHealth{ maxHealth },
	health{maxHealth}
{

}

void Character::draw(sf::RenderWindow & window){
	MapObject::draw(window);
}

float Character::getHealth(void) {
	return 0;
}

void Character::setHealth(float h) {
	if (h >= maxHealth){
		health = maxHealth;
	}
	else {
		health = h;
	}
}

void Character::collisionDetected(MapObject & mo){

}

void Character::act(sf::RenderWindow & window){

}

int Character::getExpoints(int damage){
	if (totalExpoints == 0){
		totalExpoints = 1;
	}
	int expoints = int(totalExpoints / float((int(maxHealth) / damage)));
	return expoints;
}

void Character::setDamage(int damage){
	health -= damage;
}
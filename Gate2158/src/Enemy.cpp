#include "Enemy.h"
#include <iostream>

Enemy::Enemy(
	sf::Vector2f position,
	MapObject *user,
	std::string weapon,
	float health,
	int renderLayer,
	Convex* convex,
	drawable* drawable
	) :
	Character{ health, renderLayer, drawable, position, convex },
	user{ user }
{
	isFriendly = 2;
	totalExpoints = 100;
	setVelocity(sf::Vector2f{ 10, 0 });
	this->weapon = new ProjectileWeapon(weapon, 2);
}
void Enemy::draw(sf::RenderWindow & window, sf::Vector2f drawPos){
	rotate(calculateRotation(user->getDrawPosition()));
	MapObject::draw(window, drawPos);

}
void Enemy::collisionDetected(MapObject & mo){
	sf::Vector2f velocity = getVelocity();
	move(-velocity);
	setVelocity(-velocity);

}

void Enemy::act(sf::RenderWindow & window){
	//    weapon->shoot(drawPosition, calculateRotation(user->getDrawPosition()));
	if (weapon->getAmmoInMagazine() == 0){
		weapon->reload();
		weapon->setAmmo(weapon->getMaxAmmo());
	}
	walk();
}
void Enemy::walk(){
	sf::Vector2f velocity = getVelocity();
	if (drawPosition.x < 50){
		setVelocity(sf::Vector2f{ 10, 0 });
	}
	else if (drawPosition.x > 1200){
		setVelocity(sf::Vector2f{ -10, 0 });
	}
	if (drawPosition.y < 0){
		setVelocity(sf::Vector2f{ 0, 10 });
	}
	else if (drawPosition.y > 700){

		setVelocity(sf::Vector2f{ 0, -10 });
	}
	position += velocity;
}

void Enemy::move(sf::Vector2f dir){
	position += dir;
}

float Enemy::calculateRotation(sf::Vector2f userPosition){
	sf::Vector2f pos = getDrawPosition();
	// Make vector with the difference between the two vectors, position of character and position of the mouse.
	sf::Vector2f difference{ (pos.x - userPosition.x), (pos.y - userPosition.y) };

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

void Enemy::setDamage(int damage){
	health -= damage;
	if (health < 0){
		Camera *camera = Camera::getInstance();
		camera->revmoveMapObjectOnCurrentMap(this);
	}
}
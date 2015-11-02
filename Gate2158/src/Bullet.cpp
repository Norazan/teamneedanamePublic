#include "Bullet.h"
#include "Convex.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(	
	int bulletDamage, 
	sf::Vector2f startingLocation, 
	sf::Vector2f startingVelocity, 
	float angle, 
	Weapon * weapon,
	bool isFriend
) :
	weapon{ weapon }
{
	isFriendly = isFriend;

	float size = 10;
	bullet.setRadius(size);
	bullet.setFillColor(sf::Color{ 0, 255, 0 });
	bullet.setOrigin(sf::Vector2f{ -18, 13 });
	bullet.setPosition(startingLocation);

	damage = bulletDamage;
	location = startingLocation;
	velocity = startingVelocity;
	bSpeed =20.0;
	this->angle = angle;

	bullet.setRotation(angle);
	MapObject(1);

}

void Bullet::draw(sf::RenderWindow & window){
	if (outOfBound(window) || hasCollision){
		camera->revmoveMapObjectOnCurrentMap(this);
	}
	else {
		location = sf::Vector2f(location.x + velocity.x*bSpeed, location.y - velocity.y*bSpeed);
		bullet.setPosition(location);
		position = location;
		window.draw(bullet);
	}
}

bool Bullet::outOfBound(sf::RenderWindow & window){
	if (bullet.getPosition().x > window.getSize().x || bullet.getPosition().x < 0){
		return true;
	}
	else if (bullet.getPosition().y > window.getSize().y || bullet.getPosition().y < 0){
		return true;
	}
	return false;
}

void Bullet::setCamera(Camera * a){
	camera = a;
}

void Bullet::collisionDetected(MapObject &mo){
	if (!mo.isFriend()){
		hasCollision = true;
	}
}
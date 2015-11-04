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
	int isFriend
) :
	weapon{ weapon },
	c{ Camera::getInstance() }
{
	isFriendly = isFriend;

	float size = 10;
	bullet.setRadius(size);
	if (isFriend == 1){
		bullet.setFillColor(sf::Color{ 0, 255, 0 });
	}
	if (isFriend == 2){
		bullet.setFillColor(sf::Color{ 255, 0, 0 });
	}
	bullet.setOrigin(sf::Vector2f{ -18, 13 });
	bullet.setPosition(startingLocation);
	position = startingLocation;

	damage = bulletDamage;
	location = startingLocation;
	velocity = startingVelocity;
	bSpeed =20.0;
	this->angle = angle;

	bullet.setRotation(angle);
	MapObject(2);

}

void Bullet::draw(sf::RenderWindow & window, sf::Vector2f drawPos){
	if (outOfBound(window) || hasCollision){
		c->revmoveMapObjectOnCurrentMap(this);
	}
	else {
		location = sf::Vector2f(location.x + velocity.x*bSpeed, location.y - velocity.y*bSpeed);
		bullet.setPosition(position);
		position = location;
		drawPosition = position;
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

void Bullet::collisionDetected(MapObject &mo){
	if (mo.isFriend() != isFriend()){
		hasCollision = true;
		weapon->setExpoints(mo.getExpoints(damage));
		mo.setDamage(damage);
	}
}
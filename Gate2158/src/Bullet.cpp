#include "Bullet.h"
#include "Convex.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(	
	int bulletDamage, 
	sf::Vector2f startingLocation, 
	sf::Vector2f startingVelocity, 
	sf::Vector2f drawLocation,
	float angle, 
	Weapon * weapon,
	int isFriend,
	sf::Texture & gunTexture
) :
	weapon{ weapon },
	c{ Camera::getInstance() }
{
	isFriendly = isFriend;

	float size = 20;
	bullet.setTexture(&gunTexture);
	bullet.setRadius(size);
	if (isFriend == 1){
		bullet.setFillColor(sf::Color{255, 255, 255 , 255});
	}
	if (isFriend == 2){
		bullet.setFillColor(sf::Color{ 150, 0, 0 , 255});
	}
	bullet.setOrigin(sf::Vector2f{ -18, 13 });
	bullet.setPosition(startingLocation);
	position = startingLocation;
	drawPosition = drawLocation;
	damage = bulletDamage;
	location = startingLocation;
	velocity = startingVelocity;
	bSpeed =20.0;
	this->angle = angle;

	bullet.setRotation(angle);
	MapObject(2);
	renderLayer = 2;
	drawObject = nullptr;
}

void Bullet::draw(sf::RenderWindow & window, sf::Vector2f drawPos){
	if (outOfBound(window) || hasCollision){
		c->revmoveMapObjectOnCurrentMap(this);
	}
	else {
		location = sf::Vector2f(location.x + velocity.x*bSpeed, location.y - velocity.y*bSpeed);
		bullet.setPosition(drawPosition);
		position = location;
		drawPosition = drawPos;
		window.draw(bullet);
	}
}

bool Bullet::outOfBound(sf::RenderWindow & window){
	if (drawPosition.x > window.getSize().x || drawPosition.x < 0){
		return true;
	}
	else if (drawPosition.y > window.getSize().y || drawPosition.y < 0){
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
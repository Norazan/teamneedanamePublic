#include "Bullet.h"
#include <iostream>
#include <math.h>

Bullet::Bullet(int bulletDamage, sf::Vector2f startingLocation, sf::Vector2f startingVelocity){
	bullet.setRadius(10);
	bullet.setOrigin(sf::Vector2f{ 65, 5 });
	//std::cout << "Bullet created\n";
	damage = bulletDamage;
	location = startingLocation;
	velocity = startingVelocity;
	bSpeed = 10.0;
}

Bullet::Bullet(int bulletDamage, sf::Vector2f startingLocation, sf::Vector2f startingVelocity, float angle){
	bullet.setRadius(10);
	bullet.setFillColor(sf::Color{ 0, 255, 0 });
	bullet.setOrigin(sf::Vector2f{ -18, 13 });
	bullet.setPosition(startingLocation);
	//std::cout << "Bullet created\n";
	damage = bulletDamage;
	location = startingLocation;
	velocity = startingVelocity;
	bSpeed =20.0;
	this->angle = angle;

	bullet.setRotation(angle);
}

void onHit(){

}

void Bullet::draw(sf::RenderWindow & window){
	//std::cout << "Bullet fired: " << ((bullet.getRotation()*3.1415) / 180.0)*10 << "\n";
	if (outOfBound(window)){
		//remove the bullet!
		
	}

	//pythagoras om de x verplaatsing en y verplaatsing uit te rekenen
	//float x = acos((bullet.getRotation()*3.1415)/180.0) * bSpeed;
	//float y = asin((bullet.getRotation()*3.14)/180.0) * bSpeed;

	int x = 20;
	int y = 20;

	location = sf::Vector2f(location.x + velocity.x*bSpeed, location.y - velocity.y*bSpeed);
	bullet.setPosition(location);
	window.draw(bullet);
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

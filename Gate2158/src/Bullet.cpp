#include "Bullet.h"
#include <iostream>

Bullet::Bullet(int bulletDamage, sf::Vector2f startingLocation, sf::Vector2f startingVelocity){
std::cout << "Bullet created";
damage = bulletDamage;
location = startingLocation;
velocity = startingVelocity;
sf::CircleShape bull;
bull.setFillColor(sf::Color(255, 255, 255));
}
void onHit(){

}
void Bullet::draw(sf::RenderWindow & window){
	location.x += velocity.x;
	location.y += velocity.y;
	//bull.setPosition(location);	
	//window.draw(bull);
}
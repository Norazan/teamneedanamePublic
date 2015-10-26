#include "Bullet.h"
#include <math.h>
#include <iostream>

Bullet::Bullet(int bulletDamage, sf::Vector2f startingLocation, float startAngle, sf::Vector2f startingVelocity){
std::cout << "Bullet created";
damage = bulletDamage;
location = startingLocation;
angle = startAngle;
velocity = startingVelocity;
}
void onHit(){

}
void Bullet::updateLocation(){
	location + velocity;
}
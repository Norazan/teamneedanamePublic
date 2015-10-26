#ifndef GATE2158_BULLET_H
#define GATE2158_BULLET_H

#include "MovableMapObject.h"

class Bullet{
public:
	Bullet(int bulletDamage, sf::Vector2f startingLocation, float startAngle, sf::Vector2f startingVelocity);
	void onHit();
	void updateLocation();
private:
	int damage;
	sf::Vector2f location;
	float angle;
	sf::Vector2f velocity;
};

#endif
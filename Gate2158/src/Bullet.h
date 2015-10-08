#ifndef GATE2158_BULLET_H
#define GATE2158_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet{
public:
	Bullet(int damage, sf::Vector2f startingLocation, int angle, int speed);
	void onHit();
	void updateLocation();
private:
	int damage;
	sf::Vector2f startingLocation;
	int angle;
	int speed;
};

#endif
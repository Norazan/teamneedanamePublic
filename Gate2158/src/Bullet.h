#ifndef GATE2158_BULLET_H
#define GATE2158_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet{
public:
	Bullet(int bulletDamage, sf::Vector2f startingLocation, sf::Vector2f startingVelocity);
	Bullet(int bulletDamage, sf::Vector2f startingLocation, sf::Vector2f startingVelocity, float angle);
	void onHit();
	void draw(sf::RenderWindow & window);
	bool outOfBound(sf::RenderWindow & window);
private:
	sf::CircleShape bullet;
	int damage;
	sf::Vector2f location;
	sf::Vector2f velocity;
	float bSpeed = 10;
	float angle = 0;
};

#endif
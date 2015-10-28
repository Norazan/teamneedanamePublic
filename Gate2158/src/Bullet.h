#ifndef GATE2158_BULLET_H
#define GATE2158_BULLET_H

#include <SFML/Graphics.hpp>

class Bullet{
public:
	Bullet(int bulletDamage, sf::Vector2f startingLocation, sf::Vector2f startingVelocity);
	void onHit();
	void draw(sf::RenderWindow & window);
private:
	int damage;
	sf::Vector2f location;
	sf::Vector2f velocity;
	sf::CircleShape bull;
};

#endif
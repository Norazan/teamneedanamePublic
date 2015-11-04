#ifndef GATE2158_ENEMY_H
#define GATE2158_ENEMY_H

#include "Character.h"
#include "ProjectileWeapon.h"

#define PI 3.14159265
#define angleOfAbove 270.0;
#define angleOfUnder 90.0;
#define angleOfLeft 180.0;
#define angleOfRight 0.0;

class Enemy : public Character {
public:
	Enemy(
		sf::Vector2f position, 
		MapObject *user, 
		std::string weapon, 
		float health, 
		int renderLayer, 
		Convex* convex, 
		drawable* drawable
	);
	void draw(sf::RenderWindow & window) override;
	void collisionDetected(MapObject & mo) override;
	void act(sf::RenderWindow & window) override;
private:
	void move(sf::Vector2f dir);
	float calculateRotation(sf::Vector2f userPosition);
	ProjectileWeapon *weapon;
	MapObject *user;
};

#endif
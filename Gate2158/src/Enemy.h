#ifndef GATE2158_ENEMY_H
#define GATE2158_ENEMY_H

#include "Character.h"
#include "Camera.hpp"
#include "ProjectileWeapon.h"

#define PI 3.14159265
#define angleOfAbove 270.0;
#define angleOfUnder 90.0;
#define angleOfLeft 180.0;
#define angleOfRight 0.0;

class ProjectileWeapon;

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
	void draw(sf::RenderWindow & window, sf::Vector2f drawPosition) override;
	void collisionDetected(MapObject & mo) override;
	void act(sf::RenderWindow & window) override;
	void setDamage(int damage) override;
	void walk();
private:
	void move(sf::Vector2f dir);
	float calculateRotation(sf::Vector2f userPosition);
	ProjectileWeapon *weapon;
	MapObject *user;

	//! the current rotation of the enemy in degrees.
	float currentRotation;
	//! the previous rotation of the enemy in degrees.
	float previousRotation;
	//! boolean canRotate
	bool canRotate = true;
};

#endif
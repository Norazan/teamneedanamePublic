#ifndef GATE2158_BULLET_H
#define GATE2158_BULLET_H

#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Camera.hpp"
#include "ProjectileWeapon.h"

class Bullet : public MapObject {
public:
	Bullet(int bulletDamage, sf::Vector2f startingLocation, sf::Vector2f startingVelocity, float angle, ProjectileWeapon* weapon);
	void draw(sf::RenderWindow & window) override;
	bool outOfBound(sf::RenderWindow & window);
	void setCamera(Camera *c);
private:
	sf::CircleShape bullet;
	ProjectileWeapon* weapon;
	int damage;
	sf::Vector2f location;
	sf::Vector2f velocity;
	float bSpeed = 10;
	float angle = 0;
	Camera* camera;
};

#endif
#ifndef GATE2158_BULLET_H
#define GATE2158_BULLET_H

#include "Camera.hpp"
#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Weapon.h"
class Camera;
class Bullet : public MapObject {
public:
	Bullet(
		int bulletDamage,
		sf::Vector2f startingLocation,
		sf::Vector2f startingVelocity,
		float angle,
		Weapon* weapon,
		int isFriend,
		sf::Texture & gunTexture
	);
	void draw(sf::RenderWindow & window, sf::Vector2f drawPosition) override;
	bool outOfBound(sf::RenderWindow & window);
	void collisionDetected(MapObject &mo) override;
private:
	sf::CircleShape bullet;
	Weapon* weapon;
	int damage;
	sf::Vector2f location;
	sf::Vector2f velocity;
	float bSpeed = 10;
	float angle = 0;
	bool hasCollision = false;
	Camera* c;
};

#endif
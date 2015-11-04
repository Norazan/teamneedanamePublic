#ifndef GATE2158_WEAPON_H
#define GATE2158_WEAPON_H

#include <SFML/Graphics.hpp>
class Weapon{
public:
	virtual void shoot(sf::Vector2f location, float angle) = 0;
	virtual int getAmmo() = 0;
	virtual void setAmmo(int ammo) = 0;
	virtual int calculateDamage()= 0;
	virtual void setExpoints(int expoints) = 0;
};


#endif
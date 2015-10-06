#ifndef GATE2158_WEAPON_H
#define GATE2158_WEAPON_H

#include "UserCharacter.h"
class Weapon{
public:
	virtual void shoot() = 0;
	virtual int getAmmo() = 0;
	virtual void setAmmo() = 0;
	virtual int calculateDamage()= 0;
};


#endif
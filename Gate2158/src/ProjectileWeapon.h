#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H

#include "Weapon.h"
#include "Bullet.h"
#include <vector>
#include <string>
#include "Camera.hpp"

#define PI 3.14159265

class ProjectileWeapon: public Weapon{
public:
	ProjectileWeapon(std::string weaponType, bool isFriendly);
	ProjectileWeapon();
	void shoot(sf::Vector2f location, float angle);
	int getAmmo();
	int getAmmoInMagazine();
	void setAmmo(int ammo);
	void setAmmoInMagazine(int ammo);
	int calculateDamage();
	void reload();
	void setCamera(Camera *c);
private:
	std::string weaponType;
	int attackSpeed;
	int maxAmmo;
	int currentAmmo;
	int ammoInMagazine;
	int maxAmmoInMagazine;
	int baseDamage;
	int weaponTier;
	int projectileVelocity;
	int reloadTime;
	float spread;
	float amountOfBullets;
	bool isFriendly;
	clock_t currentClock;
	clock_t previousClock = clock();
	clock_t reloadClock = clock();
	Camera * camera;
};

#endif
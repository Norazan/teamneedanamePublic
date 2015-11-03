#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H


#define PI 3.14159265

#include "Weapon.h"
#include "Bullet.h"
#include <vector>
#include <string>
#include "Camera.hpp"

struct gun{
	std::string name;
	int attackSpeed = 1;
	int maxAmmo = 1;
	int currentAmmo = 1;
	int ammoInMagazine = 1;
	int maxAmmoInMagazine = 1;
	int baseDamage = 1;
	int weaponTier = 1;
	int projectileVelocity = 1;
	int reloadTime = 1000;
	int expoints = 0;
	int nextLevelExpoints = 1;
	float spread = 0;
	float amountOfBullets = 1;
};

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
	std::string switchWeapon();
	int getExpoints();
	void setExpoints(int expoints) override;
private:
	std::string weaponType;
	bool isFriendly;
	clock_t currentClock;
	clock_t previousClock = clock();
	clock_t reloadClock = clock();
	Camera * camera;
	gun pistol;
	gun shotgun;
	gun currentGun;
};

#endif
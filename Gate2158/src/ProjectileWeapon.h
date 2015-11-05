#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H


#define PI 3.14159265

#include "Weapon.h"
#include "Bullet.h"
#include <vector>
#include <string>
#include "Camera.hpp"

class Camera;
struct gun{
	std::string name;
	double attackSpeed = 1;
	double maxAmmo = 1;
	double currentAmmo = 1;
	double ammoInMagazine = 1;
	double maxAmmoInMagazine = 1;
	double baseDamage = 1;
	double weaponTier = 1;
	double projectileVelocity = 0.5;
	double reloadTime = 1000;
	int expoints = 0;
	int nextLevelExpoints = 100;
	float spread = 0;
	float amountOfBullets = 1;
	sf::Texture gunTexture;
};

class ProjectileWeapon: public Weapon{
public:
	ProjectileWeapon(std::string weaponType, int isFriendly);
	ProjectileWeapon();
	void shoot(sf::Vector2f location, float angle) override;
	int getAmmo() override;
	int getAmmoInMagazine();
	void setAmmo(int ammo) override;
	void setAmmoInMagazine(double ammo);
	int calculateDamage() override;
	void reload();
	std::string switchWeapon();
	int getExpoints();
	void setExpoints(int expoints) override;
	int getTier();
	int getMaxAmmo();
private:
	std::string weaponType;
	int isFriendly;
	clock_t currentClock;
	clock_t previousClock = clock();
	clock_t reloadClock = clock();
	Camera *camera;
	gun pistol;
	gun shotgun;
	gun currentGun;
};

#endif
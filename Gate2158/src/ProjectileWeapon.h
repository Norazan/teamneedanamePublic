#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H

#include "Weapon.h"
#include "Bullet.h"
#include <vector>
#include <memory>

#define PI 3.14159265

class ProjectileWeapon: public Weapon{
public:
	ProjectileWeapon(int shotType);
	void shoot(sf::Vector2f location, float angle);
	int getAmmo();
	int getAmmoInMagazine();
	void setAmmo(int ammo);
	void setAmmoInMagazine(int ammo);
	int calculateDamage();
	void reload();
	void ProjectileWeapon::drawBullets(sf::RenderWindow & window);
private:
	int shotType;
	int attackSpeed;
	int maxAmmo;
	int currentAmmo;
	int ammoInMagazine;
	int maxAmmoInMagazine;
	int baseDamage;
	int weaponTier;
	int projectileVelocity;
	float spread;
	float amountOfBullets;
	std::vector<Bullet> shotBullets;
	Bullet* shotBullet;
	clock_t currentClock;
	clock_t previousClock = clock();
	double old;
};

#endif
#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H

#include "Weapon.h"
#include "Bullet.h"

#define PI 3.14159265

class ProjectileWeapon: public Weapon{
public:
	ProjectileWeapon(int shotType, int attackSpeed, int maxAmmo, int baseDamage, int maxAmmoInMagazine);
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
	Bullet* shotBullet;
};

#endif
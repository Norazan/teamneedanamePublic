#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H

#include "Weapon.h"

class ProjectileWeapon: public Weapon{
public:
	ProjectileWeapon(int shotType, int attackSpeed, int maxAmmo, int baseDamage, int maxAmmoInMagazine);
	void shoot();
	int getCurrentAmmo();
	int getAmmoInMagazine();
	void setCurrentAmmo(int ammo);
	void setAmmoInMagazine(int ammo);
	int calculateDamage();
	void reload();
private:
	int shotType;
	int attackSpeed;
	int maxAmmo;
	int currentAmmo;
	int ammoInMagazine;
	int maxAmmoInMagazine;
	int baseDamage;
	int weaponTier;

};

#endif
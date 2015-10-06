#include "ProjectileWeapon.h"

ProjectileWeapon::ProjectileWeapon(int shotType, int attackSpeed, int maxAmmo, int baseDamage, int maxAmmoInMagazine)
{
	currentAmmo = 0;
	ammoInMagazine = 0;
	weaponTier = 1;
}

void ProjectileWeapon::shoot(){

}
int ProjectileWeapon::getCurrentAmmo(){
	return currentAmmo;
}
int ProjectileWeapon::getAmmoInMagazine(){
	return ammoInMagazine;
}
void ProjectileWeapon::setCurrentAmmo(int ammo){
	currentAmmo = ammo;
}
void ProjectileWeapon::setAmmoInMagazine(int ammo){
	ammoInMagazine = ammo;
}
int ProjectileWeapon::calculateDamage(){
	return baseDamage + weaponTier;

}
void ProjectileWeapon::reload(){
	if (currentAmmo >= maxAmmoInMagazine){
		ammoInMagazine = maxAmmoInMagazine;
		currentAmmo -= maxAmmoInMagazine;
	}
	else{
		ammoInMagazine = currentAmmo;
		currentAmmo = 0;
	}

}


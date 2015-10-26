#include "ProjectileWeapon.h"
#include <SFML/Graphics.hpp>

ProjectileWeapon::ProjectileWeapon(int shotType, int attackSpeed, int maxAmmo, int baseDamage, int maxAmmoInMagazine)
{
	currentAmmo = 100;
	ammoInMagazine = 10;
	weaponTier = 1;
}

void ProjectileWeapon::shoot(sf::Vector2f location, float angle){
	sf::Vector2f startingVelocity;
	shotBullet = new Bullet(calculateDamage(), location, startingVelocity);
}
int ProjectileWeapon::getAmmo(){
	return currentAmmo;
}
int ProjectileWeapon::getAmmoInMagazine(){
	return ammoInMagazine;
}
void ProjectileWeapon::setAmmo(int ammo){
	currentAmmo = ammo;
}
void ProjectileWeapon::setAmmoInMagazine(int ammo){
	ammoInMagazine = ammo;
}
int ProjectileWeapon::calculateDamage(){
	return baseDamage + ((baseDamage / 10)* weaponTier);

}
void ProjectileWeapon::reload(){
	if (ammoInMagazine < maxAmmoInMagazine){
		if (currentAmmo >= maxAmmoInMagazine){
			ammoInMagazine += maxAmmoInMagazine;
			currentAmmo -= maxAmmoInMagazine;
		}
		else{
			ammoInMagazine += currentAmmo;
			currentAmmo = 0;
		}
	}

}


#include "ProjectileWeapon.h"

ProjectileWeapon::ProjectileWeapon(int shotType, int attackSpeed, int projectileSpeed, int maxAmmo, int baseDamage, int maxAmmoInMagazine)
{
	projectileVelocity = projectileSpeed;
	currentAmmo = 100;
	ammoInMagazine = 10;
	weaponTier = 1;
}

void ProjectileWeapon::shoot(sf::Vector2f location, float angle){
	shotBullet = new Bullet(calculateDamage(), location, angle, projectileVelocity);
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


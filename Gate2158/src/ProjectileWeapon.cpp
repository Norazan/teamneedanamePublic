#include "ProjectileWeapon.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

ProjectileWeapon::ProjectileWeapon(std::string weaponType, bool isFriendly) :
	weaponType( weaponType ),
	isFriendly{isFriendly}
{
	if (weaponType == "pistol"){
		attackSpeed = 200;
		maxAmmo = 100;
		baseDamage = 25;
		maxAmmoInMagazine = 10;
		amountOfBullets = 1;
		spread = 0;
		reloadTime = 1000;
	}
	else if (weaponType == "shotgun"){
		attackSpeed = 500;
		maxAmmo = 40;
		baseDamage = 4;
		maxAmmoInMagazine = 8;
		amountOfBullets = 8;
		spread = 0.005f;
		reloadTime = 1000;
	}
	currentAmmo = maxAmmo;
	ammoInMagazine = maxAmmoInMagazine;
	weaponTier = 1;
}

ProjectileWeapon::ProjectileWeapon(){

}

void ProjectileWeapon::shoot(sf::Vector2f location, float angle){
	currentClock = clock();
	double shootDiffTicks = currentClock - previousClock;
	double reloadDiffTicks = currentClock - reloadClock;
	double shootDiffMS = shootDiffTicks / (CLOCKS_PER_SEC / 1000);
	double reloadDiffMS = reloadDiffTicks / (CLOCKS_PER_SEC / 1000);

	if (ammoInMagazine > 0 && shootDiffMS > attackSpeed && reloadDiffMS > reloadTime){
		float radian = (angle + 90) * ((float)PI / (float)180);

		for (float i = amountOfBullets/2 - amountOfBullets; i < amountOfBullets/2; i++){
			float bulletSpread = (amountOfBullets / 2) * spread * i;
			sf::Vector2f startingVelocity{ sin(radian + bulletSpread), cos(radian + bulletSpread) };
			Bullet *bullet = new Bullet(calculateDamage(), location, startingVelocity, angle, this, isFriendly);
			bullet->setCamera(camera);
			camera->addMapObjectToCurrentMap(bullet);
		}
		ammoInMagazine -= 1;
		previousClock = currentClock;
	}
}
void ProjectileWeapon::setCamera(Camera * c){
	camera = c;
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
	if(ammoInMagazine < maxAmmoInMagazine){
		if(currentAmmo >= maxAmmoInMagazine){
			ammoInMagazine = maxAmmoInMagazine;
			currentAmmo -= maxAmmoInMagazine;
		}
		else{
			ammoInMagazine = currentAmmo;
			currentAmmo = 0;
		}
	}
	reloadClock = clock();
}


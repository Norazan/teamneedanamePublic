#include "ProjectileWeapon.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>

ProjectileWeapon::ProjectileWeapon(std::string weaponType, bool isFriendly) :
	weaponType( weaponType ),
	isFriendly{isFriendly}
{
	pistol.name = "pistol";
	pistol.attackSpeed = 200;
	pistol.maxAmmo = 100;
	pistol.baseDamage = 15;
	pistol.maxAmmoInMagazine = 10;

	shotgun.name = "shotgun";
	shotgun.attackSpeed = 200;
	shotgun.maxAmmo = 40;
	shotgun.baseDamage = 35;
	shotgun.maxAmmoInMagazine = 2;
	shotgun.amountOfBullets = 3;
	shotgun.spread = 0.09f;
	shotgun.reloadTime = 800;

	shotgun.currentAmmo = shotgun.maxAmmo;
	shotgun.ammoInMagazine = shotgun.maxAmmoInMagazine;
	pistol.currentAmmo = pistol.maxAmmo;
	pistol.ammoInMagazine = pistol.maxAmmoInMagazine;

	if (weaponType == "pistol"){
		currentGun = pistol;
	}
	else if (weaponType == "shotgun"){
		currentGun = shotgun;
	}
}

ProjectileWeapon::ProjectileWeapon(){

}

void ProjectileWeapon::shoot(sf::Vector2f location, float angle){
	currentClock = clock();
	double shootDiffTicks = currentClock - previousClock;
	double reloadDiffTicks = currentClock - reloadClock;
	double shootDiffMS = shootDiffTicks / (CLOCKS_PER_SEC / 1000);
	double reloadDiffMS = reloadDiffTicks / (CLOCKS_PER_SEC / 1000);

	if (currentGun.ammoInMagazine > 0 && shootDiffMS > currentGun.attackSpeed && reloadDiffMS > currentGun.reloadTime){
		float radian = (angle + 90) * ((float)PI / (float)180);

		for (float i = currentGun.amountOfBullets / 2 - currentGun.amountOfBullets; i < currentGun.amountOfBullets / 2; i++){
			float bulletSpread = (currentGun.amountOfBullets / 2) * currentGun.spread * i;
			sf::Vector2f startingVelocity{ sin(radian + bulletSpread), cos(radian + bulletSpread) };
			Bullet *bullet = new Bullet(calculateDamage(), location, startingVelocity, angle, this, isFriendly);
			bullet->setCamera(camera);
			camera->addMapObjectToCurrentMap(bullet);
		}
		currentGun.ammoInMagazine -= 1;
		previousClock = currentClock;
	}
}

void ProjectileWeapon::setCamera(Camera * c){
	camera = c;
}

int ProjectileWeapon::getAmmo(){
	return currentGun.currentAmmo;
}

int ProjectileWeapon::getAmmoInMagazine(){
	return currentGun.ammoInMagazine;
}

void ProjectileWeapon::setAmmo(int ammo){
	currentGun.currentAmmo = ammo;
}

void ProjectileWeapon::setAmmoInMagazine(int ammo){
	currentGun.ammoInMagazine = ammo;
}

int ProjectileWeapon::calculateDamage(){
	return currentGun.baseDamage + ((currentGun.baseDamage / 10)* currentGun.weaponTier);
}

std::string ProjectileWeapon::switchWeapon(){
	if (currentGun.name == "pistol"){
		pistol = currentGun;
		currentGun = shotgun;
	}
	else if (currentGun.name == "shotgun"){
		shotgun = currentGun;
		currentGun = pistol;
	}
	return currentGun.name;
}

void ProjectileWeapon::reload(){
	if (currentGun.ammoInMagazine < currentGun.maxAmmoInMagazine){
		if (currentGun.currentAmmo >= currentGun.maxAmmoInMagazine){
			currentGun.ammoInMagazine = currentGun.maxAmmoInMagazine;
			currentGun.currentAmmo -= currentGun.maxAmmoInMagazine;
		}
		else{
			currentGun.ammoInMagazine = currentGun.currentAmmo;
			currentGun.currentAmmo = 0;
		}
	}
	reloadClock = clock();
}

int ProjectileWeapon::getExpoints(){
	return currentGun.expoints;
}


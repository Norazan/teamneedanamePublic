#include "ProjectileWeapon.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

ProjectileWeapon::ProjectileWeapon(std::string weaponType, int isFriendly) :
	weaponType( weaponType ),
	isFriendly{ isFriendly },
	camera{ Camera::getInstance() }
{
	if (isFriendly == 2){
		pistol.attackSpeed = 1500;
		pistol.reloadTime = 1500;
		shotgun.attackSpeed = 1700;
	}
	else {
		pistol.attackSpeed = 600;
		shotgun.attackSpeed = 1200;
		shotgun.reloadTime = 800;
	}

	pistol.name = "pistol";
	pistol.maxAmmo = 100;
	pistol.baseDamage = 25;
	pistol.maxAmmoInMagazine = 10;

	shotgun.name = "shotgun";
	shotgun.maxAmmo = 36;
	shotgun.baseDamage = 10;
	shotgun.maxAmmoInMagazine = 6;
	shotgun.amountOfBullets = 3;
	shotgun.spread = 0.05f;

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
			camera->addMapObjectToCurrentMap(bullet);
		}
		currentGun.ammoInMagazine -= 1;
		previousClock = currentClock;
	}
}

int ProjectileWeapon::getAmmo(){
	return int(currentGun.currentAmmo);
}

int ProjectileWeapon::getAmmoInMagazine(){
	return int(currentGun.ammoInMagazine);
}

void ProjectileWeapon::setAmmo(int ammo){
	currentGun.currentAmmo = ammo;
}

void ProjectileWeapon::setAmmoInMagazine(double ammo){
	currentGun.ammoInMagazine = ammo;
}

int ProjectileWeapon::calculateDamage(){
	double randomDamage = rand() % int((currentGun.baseDamage/2)+5) + currentGun.baseDamage;
	return int(currentGun.baseDamage + ((randomDamage / 10)* currentGun.weaponTier));
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
	if (currentGun.ammoInMagazine < currentGun.maxAmmoInMagazine && currentGun.currentAmmo != 0){
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

int ProjectileWeapon::getTier(){
	return int(currentGun.weaponTier);
}

void ProjectileWeapon::setExpoints(int expoints){
	currentGun.expoints += expoints;
	// check if curren gun has achieved next tier.
	if (currentGun.expoints >= currentGun.nextLevelExpoints){
		++currentGun.weaponTier;
		currentGun.nextLevelExpoints = currentGun.nextLevelExpoints * 2;
		// upgrade ammo
		currentGun.maxAmmo += currentGun.maxAmmo * 0.1;
		currentGun.currentAmmo = currentGun.maxAmmo;
		currentGun.maxAmmoInMagazine += currentGun.maxAmmoInMagazine * 0.1;
		// upgrade speed
		currentGun.reloadTime -= currentGun.reloadTime * 0.1;
		currentGun.projectileVelocity += currentGun.projectileVelocity * 0.2;
		currentGun.attackSpeed -= currentGun.attackSpeed * 0.1;
		if (currentGun.name == "shotgun"){
			++currentGun.amountOfBullets;
			currentGun.spread -= float(currentGun.spread * 0.2);
		}
	}
}

int ProjectileWeapon::getMaxAmmo(){
	return int(currentGun.maxAmmo);
}


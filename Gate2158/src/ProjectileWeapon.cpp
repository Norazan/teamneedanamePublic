#include "ProjectileWeapon.h"
#include "Circle.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdlib.h>

ProjectileWeapon::ProjectileWeapon(std::string weaponType, int isFriendly) :
isFriendly{ isFriendly },
camera{ Camera::getInstance() }
{

	sf::Texture loadTexture;

	if (isFriendly == 1){
		if (!loadTexture.loadFromFile("../../Gate2158/media/textures/BulletGreen.png")){
			return;
		}
	}
	else{
		if (!loadTexture.loadFromFile("../../Gate2158/media/textures/BulletRed.png")){
			return;
		}
	}
	if (isFriendly == 2){
		pistol.attackSpeed = sf::milliseconds(1500);//1500;
		pistol.reloadTime = sf::milliseconds(1500);//1500;
		shotgun.attackSpeed = sf::milliseconds(1700);//1700;
	}
	else {
		pistol.attackSpeed = sf::milliseconds(600);//600;
		shotgun.attackSpeed = sf::milliseconds(1200);//1200;
		shotgun.reloadTime = sf::milliseconds(800);//800;
	}

	pistol.name = "pistol";
	pistol.maxAmmo = 100;
	pistol.baseDamage = 25;
	pistol.maxAmmoInMagazine = 10;
	pistol.gunTexture = loadTexture;


	shotgun.name = "shotgun";
	shotgun.maxAmmo = 36;
	shotgun.baseDamage = 10;
	shotgun.maxAmmoInMagazine = 6;
	shotgun.amountOfBullets = 3;
	shotgun.spread = 0.05f;

	shotgun.gunTexture = loadTexture;

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

void ProjectileWeapon::shoot(sf::Vector2f location, float angle, sf::Vector2f drawPosition){
	if (currentGun.ammoInMagazine > 0 && shootClock.getElapsedTime() > currentGun.attackSpeed && reloadClock.getElapsedTime() > currentGun.reloadTime){
		float radian = (angle + 90) * ((float)PI / (float)180);

		for (float i = currentGun.amountOfBullets / 2 - currentGun.amountOfBullets; i < currentGun.amountOfBullets / 2; i++){
			float bulletSpread = (currentGun.amountOfBullets / 2) * currentGun.spread * i;
			sf::Vector2f startingVelocity{ sin(radian + bulletSpread), cos(radian + bulletSpread) };
			Bullet *bullet = new Bullet(calculateDamage(), location, startingVelocity, drawPosition, angle, this, isFriendly, currentGun.gunTexture);
			camera->addMapObjectToCurrentMap(bullet);
		}
		currentGun.ammoInMagazine -= 1;
		shootClock.restart();
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
		reloadClock.restart();
	}

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
	while (currentGun.expoints >= currentGun.nextLevelExpoints){
		++currentGun.weaponTier;
		currentGun.nextLevelExpoints = currentGun.nextLevelExpoints * 2;
		// upgrade ammo
		currentGun.maxAmmo += currentGun.maxAmmo * 0.1;
		currentGun.currentAmmo = currentGun.maxAmmo;
		currentGun.maxAmmoInMagazine += currentGun.maxAmmoInMagazine * 0.1;
		// upgrade speed
		currentGun.reloadTime -= sf::seconds(currentGun.reloadTime.asSeconds() * 0.1f);
		currentGun.projectileVelocity += currentGun.projectileVelocity * 0.2;
		currentGun.attackSpeed -= sf::seconds(currentGun.attackSpeed.asSeconds() * 0.1f);
		if (currentGun.name == "shotgun"){
			++currentGun.amountOfBullets;
			currentGun.spread -= float(currentGun.spread * 0.2);
		}
	}
}

int ProjectileWeapon::getMaxAmmo(){
	return int(currentGun.maxAmmo);
}

std::vector<int> ProjectileWeapon::getWeaponExpoints(){
	if (currentGun.name == "pistol"){
		pistol = currentGun;
	}
	else {
		shotgun = currentGun;
	}
	std::vector<int> tiers;
	tiers.push_back(int(pistol.expoints));
	tiers.push_back(int(shotgun.expoints));
	return tiers;
}
void ProjectileWeapon::setWeaponExpoints(std::vector<int> expoints){
	pistol.expoints = expoints[0];
	shotgun.expoints = expoints[1];
	setExpoints(1);
}


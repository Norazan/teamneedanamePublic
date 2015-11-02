#include "ProjectileWeapon.h"
#include <SFML/Graphics.hpp>
#include <iostream>

ProjectileWeapon::ProjectileWeapon(int shotType) :
shotType{ shotType }
{
	if (shotType == 1){
		attackSpeed = 200;
		maxAmmo = 100;
		baseDamage = 25;
		maxAmmoInMagazine = 100;
		amountOfBullets = 1;
		spread = 0;
	}
	else if (shotType == 2){
		attackSpeed = 500;
		maxAmmo = 40;
		baseDamage = 4;
		maxAmmoInMagazine = 8;
		amountOfBullets = 12;
		spread = 0.005f;
	}
	currentAmmo = maxAmmo;
	ammoInMagazine = maxAmmoInMagazine;
	weaponTier = 1;
}

void ProjectileWeapon::shoot(sf::Vector2f location, float angle){
	currentClock = clock();
	double diffticks = currentClock - previousClock;
	double diffms = diffticks / (CLOCKS_PER_SEC / 1000);

	if (ammoInMagazine > 0 && diffms > attackSpeed){
		float radian = (angle + 90) * ((float)PI / (float)180);

		for (float i = amountOfBullets/2 - amountOfBullets; i < amountOfBullets/2; i++){
			float bulletSpread = (amountOfBullets / 2) * spread * i;
			std::cout << bulletSpread << "\n";
			sf::Vector2f startingVelocity{ sin(radian + bulletSpread), cos(radian + bulletSpread) };
			Bullet *bullet = new Bullet(calculateDamage(), location, startingVelocity, angle);
			bullet->setCamera(camera);
			camera->addMapObjectToCurrentMap(bullet);
		}
		ammoInMagazine -= 1;
		previousClock = currentClock;
	}
	else {
		std::cout << diffms << "\n";
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
}


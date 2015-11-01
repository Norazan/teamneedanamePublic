#include "ProjectileWeapon.h"
#include <SFML/Graphics.hpp>
#include <iostream>

ProjectileWeapon::ProjectileWeapon(int shotType, int attackSpeed, int maxAmmo, int baseDamage, int maxAmmoInMagazine)
{
	currentAmmo = 100;
	ammoInMagazine = 10;
	weaponTier = 1;
}

void ProjectileWeapon::shoot(sf::Vector2f location, float angle){
	float radian = (angle+90) * ((float)PI / (float)180);
	sf::Vector2f startingVelocity{ sin(radian), cos(radian) };

	

	shotBullets.push_back(Bullet(calculateDamage(), location, startingVelocity, angle));
	
	if (shotBullets.capacity() > 20){
		shotBullets.erase(shotBullets.begin());
	}

	//shotBullet = ;
}
void ProjectileWeapon::drawBullets(sf::RenderWindow & window){
	if (!shotBullets.empty()){
		for (auto &b : shotBullets){	
			if (b.outOfBound(window)){
				//shotBullets.erase(remove(shotBullets.begin(), shotBullets.end(), b), shotBullets.end());
				//std::cout << "Out of bound !\n";
			}
			b.draw(window);
		}
	}
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
	if (currentAmmo >= maxAmmoInMagazine && ammoInMagazine < maxAmmoInMagazine){
		ammoInMagazine = maxAmmoInMagazine;;
		currentAmmo -= ammoInMagazine;
		std::cout << "Reloaded";
	}
}


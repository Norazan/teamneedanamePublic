#include "ProjectileWeapon.h"
#include <SFML/Graphics.hpp>
#include <iostream>

ProjectileWeapon::ProjectileWeapon(int shotType, int attackSpeed, int maxAmmo, int baseDamage, int maxAmmoInMagazine) :
	attackSpeed{ attackSpeed },
	shotType{ shotType },
	maxAmmo{ maxAmmo },
	baseDamage{ baseDamage },
	maxAmmoInMagazine{maxAmmoInMagazine}
{
	currentAmmo = maxAmmo;
	ammoInMagazine = maxAmmoInMagazine;
	weaponTier = 1;
}

void ProjectileWeapon::shoot(sf::Vector2f location, float angle){
	if (ammoInMagazine > 0){
		float radian = (angle + 90) * ((float)PI / (float)180);
		sf::Vector2f startingVelocity{ sin(radian), cos(radian) };


		//std::unique_ptr<Bullet> bullet(new Bullet(calculateDamage(), location, startingVelocity, angle));
		shotBullets.push_back(Bullet(calculateDamage(), location, startingVelocity, angle));

		/*if (shotBullets.capacity() > 20){
			shotBullets.erase(shotBullets.begin());
			}*/

		ammoInMagazine -= 1;
	}
}
void ProjectileWeapon::drawBullets(sf::RenderWindow & window){
	if (!shotBullets.empty()){
		int count = 0;
		bool deleting = false; int deletingObject = 0;
		for (auto &b : shotBullets){	
			if (b.outOfBound(window)){
				deleting = true;
				deletingObject = count;
				//shotBullets.erase(remove(shotBullets.begin(), shotBullets.end(), b), shotBullets.end());
				//std::cout << "Out of bound !\n";
			}
			else {
				b.draw(window);
			}
			++count;
		}
		if (deleting){
			shotBullets.erase(shotBullets.begin() + deletingObject);
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
		int oldAmmoInMagazine = ammoInMagazine;
		ammoInMagazine = maxAmmoInMagazine;
		currentAmmo -= (ammoInMagazine - oldAmmoInMagazine);
		std::cout << "Reloaded: \ncurrentAmmo: " << currentAmmo << "\nammoInMagazine: " << ammoInMagazine << "\n\n";
	}
}


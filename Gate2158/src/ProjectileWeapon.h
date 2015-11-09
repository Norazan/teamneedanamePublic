/**
* @file ProjectileWeapon.h
* @author -
* @date -
* @version 1.0
*
* The ProjectileWeapon class is a weapon that can shoot bullets
*/


#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H

#define PI 3.14159265

#include "Weapon.h"
#include "Bullet.h"
#include <vector>
#include <string>
#include "Camera.hpp"

class Camera;
/** Struct gun */
struct gun{
	std::string name;
	double attackSpeed = 1;
	double maxAmmo = 1;
	double currentAmmo = 1;
	double ammoInMagazine = 1;
	double maxAmmoInMagazine = 1;
	double baseDamage = 1;
	double weaponTier = 1;
	double projectileVelocity = 0.5;
	double reloadTime = 1000;
	int expoints = 0;
	int nextLevelExpoints = 100;
	float spread = 0;
	float amountOfBullets = 1;
	sf::Texture gunTexture;
};

class ProjectileWeapon: public Weapon{
public:
	/**
	* Constructor that sets the variable of the ProjectileWeapon.
	*
	* @param weaponType
	*		A string, with the name of the weapon
	* @param isFriendly
	*		A number to reference to the owner of the weapon
	*/
	ProjectileWeapon(std::string weaponType, int isFriendly);
	/**
	* Checks first if the weapon is ready to shoot with attackSpeed,
	* If it's ready to shoot, it wil make a bullet and add the bullet to the map.
	*
	* @param location
	*		The start location of the bullet 
	* @param angle
	*		The angle of the bullet
	*/
	void shoot(sf::Vector2f location, float angle) override;
	/**
	* Returns the ammo of the current gun
	*
	* @return
	*		The ammo of the current gun
	*/
	int getAmmo() override;
	/**
	* Returns the ammo in the magazine of the current gun
	*
	* @return
	*		The ammo in the magazine of the current gun
	*/
	int getAmmoInMagazine();
	/**
	* Sets the ammo of the current gun
	*
	* @param ammo
	*		The ammo that will be set
	*/
	void setAmmo(int ammo) override;
	/**
	* Sets the ammo in the magazine of the current gun
	*
	* @param ammo
	*		The ammo that will be set
	*/
	void setAmmoInMagazine(double ammo);
	/**
	* Calculates the damage of the bullet
	*
	* @return
	*		The damage
	*/
	int calculateDamage() override;
	/**
	* Sets the ammo in magazine to his max and reduced the ammo of the current gun
	*/
	void reload();
	/**
	* Current gun is the next weapon, so you switch from weapon
	*
	* @return
	*		The name of the new weapon
	*/
	std::string switchWeapon();
	/**
	* Returns the expoints of the current gun
	*
	* @return
	*		The expoints of the current gun
	*/
	int getExpoints();
	/**
	* Sets the expoints of the current gun, and checked if the gun has leveled.
	*
	* @param expoints
	*		The expoints that will be set
	*/
	void setExpoints(int expoints) override;
	/**
	* Returns the tier of the current gun
	*
	* @return
	*		The tier of the current gun
	*/
	int getTier();
	/**
	* Returns the maximum ammo of the current gun
	*
	* @return
	*		The maximum ammo of the current gun
	*/
	int getMaxAmmo();
	/**
	* Returns a list of the expoints of the guns
	*
	* @return
	*		The a list of the expoints of the guns
	*/
	std::vector<int> getWeaponExpoints();
	/**
	* Sets all expoints of the guns.
	*
	* @param tiers
	*		A list of expoints of the guns
	*/
	void setWeaponExpoints(std::vector<int> expoints);
private:
	int isFriendly;						/** A number to reference to the owner of the weapon */
	clock_t currentClock;				/** The current clock */
	clock_t previousClock = clock();	/** The clock when last been shot */
	clock_t reloadClock = clock();		/** The clock when last been reloaded */
	Camera *camera;						/** The camera used to add bullets to the curren map */
	gun pistol;							/** A struct with values of the pistol */
	gun shotgun;						/** A struct with values of the shotgun */
	gun currentGun;						/** A struct with values of the current gun */
};

#endif
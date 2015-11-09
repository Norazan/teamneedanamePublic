#ifndef GATE2158_PROJECTILEWEAPON_H
#define GATE2158_PROJECTILEWEAPON_H


#define PI 3.14159265

#include "Weapon.h"
#include "Bullet.h"
#include <vector>
#include <string>
#include "Camera.hpp"

class Camera;
struct gun{
	std::string name;
	sf::Time attackSpeed = sf::seconds(1);
	sf::Time reloadTime = sf::seconds(3);
	double maxAmmo = 1;
	double currentAmmo = 1;
	double ammoInMagazine = 1;
	double maxAmmoInMagazine = 1;
	double baseDamage = 1;
	double weaponTier = 1;
	double projectileVelocity = 0.5;
	int expoints = 0;
	int nextLevelExpoints = 100;
	float spread = 0;
	float amountOfBullets = 1;
	sf::Texture gunTexture;
};

class ProjectileWeapon: public Weapon{
public:
	ProjectileWeapon(std::string weaponType, int isFriendly);
	ProjectileWeapon();
	void shoot(sf::Vector2f location, float angle) override;
	int getAmmo() override;
	int getAmmoInMagazine();
	void setAmmo(int ammo) override;
	void setAmmoInMagazine(double ammo);
	int calculateDamage() override;
	void reload();
	std::string switchWeapon();
	int getExpoints();
	void setExpoints(int expoints) override;
	int getTier();
	int getMaxAmmo();
	std::vector<int> getWeaponExpoints();
	void setWeaponExpoints(std::vector<int> tiers);
private:
	std::string weaponType;
	int isFriendly;
	sf::Clock shootClock;
	sf::Clock reloadClock;
	Camera *camera;
	gun pistol;
	gun shotgun;
	gun currentGun;
};

#endif
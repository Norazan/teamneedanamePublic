//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAP_H
#define GATE2158_MAP_H

#include "Sprite.h"
#include "Rectangle.h"
#include "MapObject.h"
#include "UserCharacter.h"
#include <vector>

class UserCharacter;

class Map {
public:
    Map();
	Map(int layers);
	~Map();
    void addMapObject(MapObject *object);
	void removeMapObject(std::vector<MapObject*> removeObject);
	std::vector<MapObject*>& getAllMapObjects();
	std::vector<MapObject*>* getMapObjectsInRegion(sf::Vector2f pointA, sf::Vector2f pointB);
	int getLayers();
	void setLayers(int layers);
	void loadFromFile(std::string filename);
	MapObject *getCurrentPlayer();
	UserCharacter *player;
private:
	int layers;
	std::vector<MapObject*> mapObjects;
	MapObject *currentPlayer;
	std::vector<sf::Vector2f> wall;
	std::vector<sf::Vector2f> enemyHit;
	std::vector<sf::Vector2f> userHitbox;
	std::vector<sf::Vector2f> finishHitbox;
	Convex *convexWall;
	Convex *convexUser;
	Convex *convexEnemy;
	Convex *convexFinish;
	Sprite *enemySprite;
	Sprite *enemyShotgun;
	Sprite *enemyPistol;
	Sprite *characterGunSprite;
	Sprite *wallSprite;
	Sprite *finishSprite;
	Sprite *healthSprite;
};


#endif //GATE2158_MAP_H

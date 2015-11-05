//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAP_H
#define GATE2158_MAP_H

#include "Sprite.h"
#include "Rectangle.h"
#include "MapObject.h"
#include <vector>

class Map {
public:
    Map();
	Map(int layers);
    void addMapObject(MapObject *object);
	void removeMapObject(std::vector<MapObject*> removeObject);
	std::vector<MapObject*>& getAllMapObjects();
	std::vector<MapObject*>* getMapObjectsInRegion(sf::Vector2f pointA, sf::Vector2f pointB);
	int getLayers();
	void setLayers(int layers);
	void loadFromFile(std::string filename);
	MapObject *getCurrentPlayer();
private:
	int layers;
	std::vector<MapObject*> mapObjects;
	MapObject *currentPlayer;
	std::vector<sf::Vector2f> wall;
	std::vector<sf::Vector2f> enemyHit;
	std::vector<sf::Vector2f> userHitbox;
	Convex *convexWall;
	Convex *convexUser;
	//Convex convex3(squarePointss, sf::Vector2f(400, 400), sf::Vector2f(20, 20));
	Convex *convexEnemy;
	Sprite *enemySprite;
	Sprite *characterGunSprite;
	Sprite *wallSprite;
};


#endif //GATE2158_MAP_H

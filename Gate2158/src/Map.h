//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAP_H
#define GATE2158_MAP_H

#include "Rectangle.h"
#include "MapObject.h"
#include <vector>
#include <string>

class Rectangle;
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
	void searchPlayerInLoadedMap(sf::Vector2f position, sf::Vector2u dimensions, const int size, sf::Image mapImage);
	int layers;
	std::vector<MapObject*> mapObjects;
	MapObject *currentPlayer;
	std::vector<sf::Vector2f> wall{
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 32, 0 },
		sf::Vector2f{ 32, 32 },
		sf::Vector2f{ 0, 32 }
	};

	std::vector<sf::Vector2f> enemyHit{
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 50, 0 },//fds;skdf
		sf::Vector2f{ 50, 50 },
		sf::Vector2f{ 0, 50 }
	};

	std::vector<sf::Vector2f> userHitbox{
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 50, 0 },
		sf::Vector2f{ 50, 50 },
		sf::Vector2f{ 0, 50 }
	};
	Convex *convexWall;
	Convex *convexUser;
	//Convex convex3(squarePointss, sf::Vector2f(400, 400), sf::Vector2f(20, 20));
	Convex *convexEnemy;
	Rectangle *recEnemy;
	Rectangle *recCharacter;
	Rectangle *recWall;
	//Sprite *enemySprite;
	//Sprite *characterGunSprite;
};


#endif //GATE2158_MAP_H

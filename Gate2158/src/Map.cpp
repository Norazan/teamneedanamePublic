//
// Created by martijn on 9/28/15.
//

#include "Map.h"
#include "Wall.h"
#include "UserCharacter.h"
#include "Enemy.h"
#include <iostream>
#include <string>

Map::Map(){

}

Map::Map(int layers) :
   layers{layers}
{
	wall.push_back(sf::Vector2f{ 0, 0 });
	wall.push_back(sf::Vector2f{ 32, 0 });
	wall.push_back(sf::Vector2f{ 32, 32 });
	wall.push_back(sf::Vector2f{ 0, 32 });
	enemyHit.push_back(sf::Vector2f{ 0, 0 });
	enemyHit.push_back(sf::Vector2f{ 50, 0 });
	enemyHit.push_back(sf::Vector2f{ 50, 50 });
	enemyHit.push_back(sf::Vector2f{ 0, 50 });
	userHitbox.push_back(sf::Vector2f{ 0, 0 });
	userHitbox.push_back(sf::Vector2f{ 50, 0 });
	userHitbox.push_back(sf::Vector2f{ 50, 50 });
	userHitbox.push_back(sf::Vector2f{ 0, 50 });
}

void Map::addMapObject(MapObject *object) {
	mapObjects.push_back(object);
}

void Map::removeMapObject(std::vector<MapObject*> removeObjects){
	// for every object that need to be removed, remove.
	for (auto & object : removeObjects){
		int count = 0, removeObjectCount = -1;
		for (auto & mo : mapObjects){
			if (object == mo){
				removeObjectCount = count;
				break;
			}
			++count;
		}
		MapObject *deletingObject = mapObjects[removeObjectCount];
		mapObjects.erase(mapObjects.begin() + removeObjectCount);
		deletingObject->~MapObject();
	}
	
}

std::vector<MapObject*>& Map::getAllMapObjects(){
	return this->mapObjects;
}

void Map::setLayers(int layers){
    this->layers = layers;
}

int Map::getLayers(){
    return layers;
}

void Map::loadFromFile(const std::string filename){
	sf::Image mapImage;
	mapImage.loadFromFile(filename);
	sf::Vector2u dimensions = mapImage.getSize();

	std::cout << "Loading map with size" << "(" << dimensions.x << "," << dimensions.y << ")" << std::endl;

	convexUser = new Convex(userHitbox, sf::Vector2f(0, 0), sf::Vector2f(25, 25));
	convexEnemy = new Convex(enemyHit, sf::Vector2f(0, 0), sf::Vector2f(25, 25));
	convexWall = new Convex(wall, sf::Vector2f(0, 0), sf::Vector2f(16, 16));

	enemySprite = new Sprite("../../Gate2158/media/textures/Enemy_BIG.png");
	enemyShotgun = new Sprite("../../Gate2158/media/textures/Enemy_Shotgun.png");
	enemyPistol = new Sprite("../../Gate2158/media/textures/Enemy_Pistol.png");

	wallSprite = new Sprite("../../Gate2158/media/textures/m-001.png");
	characterGunSprite = new Sprite("../../Gate2158/media/textures/Player_BIG.png");

	const int size = 32;
	sf::Vector2f position = sf::Vector2f{ 0, 0 };


	for (unsigned int i = 0; i < dimensions.y; ++i){
		for (unsigned int j = 0; j < dimensions.x; ++j){
			position.y = (float)i*size;
			position.x = (float)j*size;
			sf::Color color = mapImage.getPixel(j, i);
			if (color.r == 0x00 && color.g == 0x00 && color.b == 0x00){
				MapObject *obj = new MapObject(3, wallSprite, position, convexWall);
				addMapObject(obj);
			}
			if(color.r == 0x00 && color.g == 0x00 && color.b == 0xFF){
				MapObject *enemy = new Enemy(position, currentPlayer, "pistol", 250, 1, convexEnemy, enemyPistol);
				addMapObject(enemy);
			}
			if(color.r == 0x00 && color.g == 0xFF && color.b == 0x00){
				MapObject *enemy2 = new Enemy(position, currentPlayer, "shotgun", 400, 1, convexEnemy, enemyShotgun);
				addMapObject(enemy2);
			}
			else if (color.r == 0xFF && color.g == 0x00 && color.b == 0x00){
				currentPlayer = new UserCharacter(1000, 0, characterGunSprite, sf::Vector2f{ 300, 500 }, convexUser);
				addMapObject(currentPlayer);
			}
		}
	}
}

std::vector<MapObject *> *Map::getMapObjectsInRegion(sf::Vector2f topLeft, sf::Vector2f bottomRight){
    std::vector<MapObject *> *objectsInRegion = new std::vector<MapObject *>;
    for(const auto & obj : mapObjects){
        sf::Vector2f position = obj->getPosition();
        if(
                position.x >= topLeft.x &&
                position.x <= bottomRight.x &&
                position.y >= topLeft.y &&
                position.y <= bottomRight.y
        ){
            objectsInRegion->push_back(obj);
        }
		else if (obj->getRenderLayer() == 2){
			objectsInRegion->push_back(obj);
		}

    }
    return objectsInRegion;
}

MapObject *Map::getCurrentPlayer(){
	return currentPlayer;
}

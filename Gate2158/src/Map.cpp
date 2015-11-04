//
// Created by martijn on 9/28/15.
//

#include <iostream>
#include "Map.h"
#include "Rectangle.h"
#include "MapObject.h"
#include "Wall.h"

Map::Map(){

}

Map::Map(int layers) :
   layers{layers}
{
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

    const int size = 32;
   // drawable *draw;
   // MapObject *obj;
    sf::Vector2f position;
    for(unsigned int i = 0; i < dimensions.y; ++i){
        for(unsigned int j = 0; j < dimensions.x; ++j){
            position.y = (float) i*size;
            position.x = (float) j*size;
            sf::Color color = mapImage.getPixel(j, i);
            if(color.r == 0x00){ //Wall-type objecct, can be a wall, a fence etc
                if(color.g == 0x00){ //Regular solid wall
                    if(color.b == 0x00){//default wall
                        MapObject *obj = new Wall(0, position);
                        addMapObject(obj);
                    }
                }

            }

        }
    }

}

std::vector<MapObject *> *Map::getMapObjectsInRegion(sf::Vector2f topLeft, sf::Vector2f bottomRight){
    std::vector<MapObject *> *objectsInRegion = new std::vector<MapObject *>;
    for(auto obj : mapObjects){
        sf::Vector2f position = obj->getPosition();
        if(
                position.x >= topLeft.x &&
                position.x <= bottomRight.x &&
                position.y >= topLeft.y &&
                position.y <= bottomRight.y
                ){
            objectsInRegion->push_back(obj);
        }

    }
    return objectsInRegion;
}

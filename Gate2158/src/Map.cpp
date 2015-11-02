//
// Created by martijn on 9/28/15.
//

#include "Map.h"

Map::Map() {

}

Map::Map(int layers) :
layers{ layers }
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
		mapObjects.erase(mapObjects.begin() + removeObjectCount);
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

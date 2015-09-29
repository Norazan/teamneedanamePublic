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

void Map::addMapObject(MapObject object) {
	mapObjects.push_back(object);
}

std::vector<MapObject>& Map::getAllMapObjects(){
	return this->mapObjects;
}

void Map::setLayers(int layers){
	this->layers = layers;
}

int Map::getLayers(){
	return layers;
}

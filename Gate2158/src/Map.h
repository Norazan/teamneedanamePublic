//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAP_H
#define GATE2158_MAP_H


#include "MapObject.h"
#include <vector>
#include <string>

class Map {
public:
    Map();
	Map(int layers);
    void addMapObject(MapObject *mapObject);
	void removeMapObject(std::vector<MapObject*> removeObject);
	std::vector<MapObject*>& getAllMapObjects();
	int getLayers();
	void setLayers(int layers);
	void loadFromFile(std::string filename);
private:
	int layers;
	std::vector<MapObject*> mapObjects;
};


#endif //GATE2158_MAP_H

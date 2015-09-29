//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAP_H
#define GATE2158_MAP_H


#include "MapObject.h"
#include <vector>

class Map {
public:
    Map();
	Map(int layers);
    void addMapObject(MapObject);
	std::vector<MapObject>& getAllMapObjects();
	int getLayers();
	void setLayers(int layers);
private:
	int layers;
	std::vector<MapObject> mapObjects;
};


#endif //GATE2158_MAP_H

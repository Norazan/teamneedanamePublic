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
    void addMapObject(MapObject);
private:
	std::vector<MapObject> mapObjects;
};


#endif //GATE2158_MAP_H

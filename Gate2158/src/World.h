
#ifndef GATE2158_WORLD_HPP
#define GATE2158_WORLD_HPP

#include "Map.h"

class World {
public:
	World();
	Map getCurrentMap();
	void addMap(Map m);
private:
	Map currentMap;
	Map maps[];
};


#endif //GATE2158_WORLD_HPP
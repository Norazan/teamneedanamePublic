
#ifndef GATE2158_WORLD_HPP
#define GATE2158_WORLD_HPP

#include "Map.h"

class World {
public:
	World(float worldSeed = 0.0);
	Map& getCurrentMap();
	void addMap(Map m);
private:
	Map currentMap;
	Map maps[10];
	float worldSeed;
};


#endif //GATE2158_WORLD_HPP
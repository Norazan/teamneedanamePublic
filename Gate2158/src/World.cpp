// Created by Ole on 29-9-2015
// 
// 

#include "World.h"

World::World(float worldSeed){
	//Should be loading/generating a file here, for now we use seed 0 which is nothing ~
	//MapLoader(worldSeed);
}

Map& World::getCurrentMap(){
	return maps[currentMap];
}

void World::addMap(Map &m){
	maps[mapCount++] = m;
}

void World::nextMap(){
	++currentMap;
}

int World::getCurrentMapCount(){
	return currentMap;
}
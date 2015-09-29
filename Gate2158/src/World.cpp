// Created by Ole on 29-9-2015
// 
// 

#include "World.h"

World::World(float worldSeed){
	//Should be loading/generating a file here, for now we use seed 0 which is nothing ~
	//MapLoader(worldSeed);
}

Map* World::getCurrentMap(){
	return & currentMap;
}

void World::addMap(Map m){

}

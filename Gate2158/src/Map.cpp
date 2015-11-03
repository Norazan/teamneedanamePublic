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
    drawable *draw;
    MapObject *obj;
    sf::Vector2f position;
    for(int i = 0; i < dimensions.y; ++i){
        for(int j = 0; j < dimensions.x; ++j){
            position.y = i*size;
            position.x = j*size;
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

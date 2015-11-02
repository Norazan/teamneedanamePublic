//
// Created by martijn on 9/28/15.
//

#include <iostream>
#include "Map.h"
#include "Rectangle.h"

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

    std::cout << "(" << dimensions.x << "," << dimensions.y << ")" << std::endl;

    for(int i = 0; i < dimensions.y; ++i){
        for(int j = 0; j < dimensions.x; ++j){
            sf::Color color = mapImage.getPixel(j, i);
            if(color == sf::Color::White){
                drawable *rect = new Rectangle(sf::Vector2f{ float(j * 10), float(i * 10) }, sf::Vector2f{10.0, 10.0}, sf::Color::Magenta);
                MapObject *obj = new MapObject(0, rect);
                addMapObject(obj);
            }
        }
    }

}

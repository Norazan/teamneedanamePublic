//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAPOBJECT_H
#define GATE2158_MAPOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "drawable.h"

class MapObject {
public:
	MapObject();
	MapObject(int renderLayer, drawable* drawables);
	void rotate(float rotation);
    float getAngle();
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();
	void setRenderLayer(int renderLayer);
	int getRenderLayer();
	sf::Vector2f getSize();
	void draw(sf::RenderWindow & window);
private:
	drawable* drawObject;
    unsigned int colorCode;
    bool isSolid;
    float angle;
	int renderLayer;
};


#endif //GATE2158_MAPOBJECT_H

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
	MapObject(int renderLayer, drawable *drawable);
	void setAngle(float angle);
    float getAngle();
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();
	void setRenderLayer(int renderLayer);
	int getRenderLayer();
	void draw(sf::RenderWindow & window);
private:
	drawable *drawObject;
    sf::Vector2f position;
    unsigned int colorCode;
    bool isSolid;
    float angle;
	int renderLayer;
};


#endif //GATE2158_MAPOBJECT_H

//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAPOBJECT_H
#define GATE2158_MAPOBJECT_H

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "drawable.h"
#include "Convex.h"

class MapObject {
public:
	MapObject();
	MapObject(int renderLayer, drawable* drawables);
	MapObject(int renderLayer, drawable* drawables, Convex* hitbox);
	void rotate(float rotation);
    float getRotation();
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();
	void setRenderLayer(int renderLayer);
	int getRenderLayer();
	sf::Vector2f getSize();
	std::vector<sf::Vector2f> getConvexPoints();

	virtual void draw(sf::RenderWindow & window);

	void setHitbox(Convex *Hitbox);
	Convex* getHitbox();

private:
	drawable* drawObject;
	Convex* Hitbox = nullptr;
    unsigned int colorCode;
    bool isSolid;
    float angle;
	int renderLayer;
};


#endif //GATE2158_MAPOBJECT_H

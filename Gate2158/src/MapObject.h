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
	MapObject(int renderLayer, drawable* drawable, sf::Vector2f position);
	MapObject(int renderLayer, drawable* drawables, sf::Vector2f position, Convex* hitbox);
	MapObject::MapObject(int renderLayer);
	void rotate(float rotation);
    float getRotation();
	void setAngle(float angle);
    float getAngle();
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();
	void setRenderLayer(int renderLayer);
	int getRenderLayer();
	sf::Vector2f getSize();
	std::vector<sf::Vector2f> getConvexPoints();
	sf::Vector2f getOrigin();
	int isFriend();
	virtual int getExpoints();
	virtual void act(sf::RenderWindow & window);
	virtual void draw(sf::RenderWindow & window);
	void setHitbox(Convex *Hitbox);
	Convex* getHitbox();
	virtual void collisionDetected(MapObject & mo);

private:
	Convex* Hitbox = nullptr;
    bool isSolid;
    float angle;

protected:
	drawable *drawObject;
	int renderLayer;
	int expointOnHit = 1000;
	sf::Vector2f position;
	int isFriendly = 0;
};


#endif //GATE2158_MAPOBJECT_H

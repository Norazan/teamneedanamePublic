//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MOVABLEMAPOBJECT_H
#define GATE2158_MOVABLEMAPOBJECT_H

#include "MapObject.h"
#include <SFML/Graphics.hpp>

class MovableMapObject : public MapObject {
public:
	MovableMapObject(int renderLayer, drawable* drawable, sf::Vector2f position, Convex* convex);
	void setVelocity(sf::Vector2f v);
    sf::Vector2f getVelocity();
	virtual void draw(sf::RenderWindow & window) override;
	virtual void collisionDetected(MapObject & mo) override;
	virtual void act(sf::RenderWindow & window) override;
	virtual int getExpoints(int damage) override;
	virtual void setDamage(int damage) override;

private:
    sf::Vector2f velocity;
};


#endif //GATE2158_MOVABLEMAPOBJECT_H

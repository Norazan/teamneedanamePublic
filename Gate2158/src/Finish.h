//
// Created by Ole on 6/11/15.
//

#include "MapObject.h"

#ifndef GATE2158_FINISH_H
#define GATE2158_FINISH_H

class Finish : public MapObject {
public:
	Finish(int renderLayer, drawable* drawable, sf::Vector2f position, Convex * hitbox);
	void draw(sf::RenderWindow &window, sf::Vector2f drawPosition);
	void collisionDetected(MapObject &mo) override;
};

#endif
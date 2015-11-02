//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_CHARACTER_H
#define GATE2158_CHARACTER_H


#include "MovableMapObject.h"

class Character : public MovableMapObject {
public:
	//! Constructor
	//
	//! @parameter maxHealth
	//! @parameter renderLayer
	//! @parameter drawable
	Character(float maxHealth, int renderLayer, drawable* drawable, Convex* convex);

	//! Function draw
	//
	//! @parameter window
	//! Draws the drawable
	virtual void draw(sf::RenderWindow & window) override;

protected:
	//! Function getHealth
	//
	//! Returns health
    float getHealth(void);

	//! Function setHealth
	//
	//! @parameter h = health
	//! Set health
    void setHealth(float h);


	virtual void collisionDetected(MapObject & mo) override;

    float health;
    float maxHealth;
};


#endif //GATE2158_CHARACTER_H

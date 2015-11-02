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
	Character(float maxHealth, int renderLayer, drawable* drawable);

	//! Function draw
	//
	//! @parameter window
	//! Draws the drawable
	virtual void draw(sf::RenderWindow & window) override;

protected:
    float health;
    float maxHealth;
};


#endif //GATE2158_CHARACTER_H

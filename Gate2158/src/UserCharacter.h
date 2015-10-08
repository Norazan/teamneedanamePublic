//
// Created by Thijs on 9/29/15.
//

#ifndef GATE2158_USERCHARACTER_H
#define GATE2158_USERCHARACTER_H

#include "Character.h"
#include "UserInput.h"
#include <SFML/Graphics.hpp>

#define PI 3.14159265
#define angleOfAbove 270.0;
#define angleOfUnder 90.0;
#define angleOfLeft 180.0;
#define angleOfRight 0.0;

class UserCharacter : public Character {
public:
	UserCharacter(float maxHealth, int renderLayer, drawable* drawable);
	void draw(sf::RenderWindow & window) override;

private:
	void move(sf::Vector2f dir);
	void processKeys();
	void processMouse(sf::RenderWindow & window);
	float calculateRotation(sf::Vector2i mousePosition);
	UserInput input;
	int speed = 10;
};

#endif //GATE2158_USERCHARACTER_H
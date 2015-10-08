//
// Created by Thijs on 9/29/15.
//

#ifndef GATE2158_USERCHARACTER_H
#define GATE2158_USERCHARACTER_H

#include "Character.h"
#include <SFML/Graphics.hpp>

class UserCharacter : public Character {
public:
	UserCharacter(float maxHealth, int renderLayer, drawable* drawable);

	void draw(sf::RenderWindow & window);

	void move(sf::Vector2f dir);

private:
};

#endif //GATE2158_USERCHARACTER_H
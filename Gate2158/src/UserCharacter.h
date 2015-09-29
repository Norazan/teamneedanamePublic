//
// Created by Thijs on 9/29/15.
//

#ifndef GATE2158_USERCHARACTER_H
#define GATE2158_USERCHARACTER_H

//#include "Character.h"

class UserCharacter{
public:
	UserCharacter(
		sf::Vector2f charSize,
		sf::Vector2f charInitPos,
		sf::Color charColor
	);

	void draw(sf::RenderWindow & window) const;

	void move(sf::Vector2f dir) const;

private:
	sf::Vector2f charSize;
	sf::Vector2f charInitPos;
	sf::Color charColor;
	sf::RectangleShape character;
};

#endif //GATE2158_USERCHARACTER_H
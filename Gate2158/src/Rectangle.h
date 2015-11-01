//
// Created by ole on 10/1/15.
//

#ifndef GATE2158_RECTANGLE_H
#define GATE2158_RECTANGLE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Rectangle : public drawable {
public:
	Rectangle(sf::Vector2f size, sf::Color color);
	void draw(sf::RenderWindow &window, sf::Vector2f &position) override;
private:
	sf::RectangleShape rectangle;
};

#endif //GATE2158_RECTANGLE_H
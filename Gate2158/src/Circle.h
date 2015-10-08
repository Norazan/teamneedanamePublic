//
// Created by ole on 10/6/15.
//

#ifndef GATE2158_CIRCLE_H
#define GATE2158_CIRCLE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Circle : public drawable {
public:
	Circle(sf::Vector2f pos, float radius, sf::Color color);
	void draw(sf::RenderWindow &window) override;
	sf::Vector2f getSize() override;
	float getRotation() override;
	void setRotation(float rotation) override;
private:
	sf::CircleShape circle;
};

#endif //GATE2158_CIRCLE_H
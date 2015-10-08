//
// Created by ole on 10/3/15.
//

#ifndef GATE2158_TEXT_H
#define GATE2158_TEXT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "drawable.h"

class Text : public drawable {
public:
	Text(
		std::string text, 
		sf::Vector2f pos, 
		sf::Text::Style style = sf::Text::Style::Regular, 
		sf::Color color = sf::Color::Black, 
		int size = 30,
		std::string font = "SF Electrotome.ttf"
	);
	Text(
		sf::String t,
		sf::Vector2f pos,
		sf::Text::Style style,
		sf::Color color,
		int size,
		sf::Font *font
		);
	void draw(sf::RenderWindow &window) override;
	sf::Vector2f getSize() override;
	float getRotation() override;
	void setRotation(float rotation) override;
private:
	sf::Text text;
};

#endif //GATE2158_TEXT_H
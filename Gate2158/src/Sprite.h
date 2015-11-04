//
// Created by ole on 10/2/15.
//

#ifndef GATE2158_SPRTIE_H
#define GATE2158_SPRITE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Sprite : public drawable {
public:
	Sprite(std::string name);
	void draw(sf::RenderWindow &window, sf::Vector2f &position);
	sf::Vector2f getSize() override;
	float getRotation() override;
	void setRotation(float rotation) override;
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif //GATE2158_SPRITE_H
//
// Created by ole on 10/2/15.
//

#ifndef GATE2158_SPRTIE_H
#define GATE2158_SPRITE_H

#include <SFML/Graphics.hpp>
#include "drawable.h"

class Sprite : public drawable {
public:
	Sprite(sf::Vector2f pos, std::string name);
	void draw(sf::RenderWindow &window) override;
private:
	sf::Texture texture;
	sf::Sprite sprite;
};

#endif //GATE2158_SPRITE_H
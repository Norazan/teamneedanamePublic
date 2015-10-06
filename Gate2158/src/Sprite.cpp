//
// Created by ole on 10/2/15.
//

#include "Sprite.h"
#include <iostream>

Sprite::Sprite(sf::Vector2f pos, std::string name) :
	drawable(pos)
{
	if (!texture.loadFromFile(name)){
		std::cout << "can't load the sprite: " << name << std::endl;
	}
	sprite.setTexture(texture);
}

void Sprite::draw(sf::RenderWindow &window){
	sprite.setPosition(getPosition());
	window.draw(sprite);
}
//
// Created by ole on 10/2/15.
//

#include "Sprite.h"
#include <iostream>

Sprite::Sprite(std::string name)
{
	if (!texture.loadFromFile(name)){
		std::cout << "can't load the sprite: " << name << std::endl;
	}
	sprite.setTexture(texture);
}

void Sprite::draw(sf::RenderWindow &window, sf::Vector2f &position){
	sprite.setPosition(position);
	window.draw(sprite);
}
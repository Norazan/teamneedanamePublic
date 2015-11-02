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
	sf::Vector2f size = getSize();
	sf::Vector2f center{ size.x / 2, size.y / 2 };
	sprite.setOrigin(center);
}

void Sprite::draw(sf::RenderWindow &window){
	sprite.setPosition(getPosition());
	window.draw(sprite);
}

sf::Vector2f Sprite::getSize(){
	sf::Vector2f size;
	size.x = sprite.getLocalBounds().width;
	size.y = sprite.getLocalBounds().height;
	return size;
}

float Sprite::getRotation(){
	return sprite.getRotation();
}

void Sprite::setRotation(float rotation){
	sprite.setRotation(rotation);
}
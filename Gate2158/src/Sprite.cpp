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
	sf::Vector2f size = getSize();
	sf::Vector2f center{ size.x / 2, size.y / 2 };
	sprite.setOrigin(center);
}

void Sprite::draw(sf::RenderWindow &window, sf::Vector2f &position){
	sprite.setPosition(position);
	window.draw(sprite);
}

sf::Vector2f Sprite::getSize(){
	sf::Vector2f size;
	size.x = sprite.getGlobalBounds().width;
	size.y = sprite.getGlobalBounds().height;
	return size;
}

float Sprite::getRotation(){
	return sprite.getRotation();
}

void Sprite::setRotation(float rotation){
	sprite.setRotation(rotation);
}
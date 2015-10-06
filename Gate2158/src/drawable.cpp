//
// Created by ole on 10/1/15.
//

#include "drawable.h"

drawable::drawable(sf::Vector2f pos){
	position = pos;
}

void drawable::draw(sf::RenderWindow &window){
	
}

void drawable::setPosition(sf::Vector2f pos){
	position = pos;
}
sf::Vector2f drawable::getPosition(){
	return position;
}
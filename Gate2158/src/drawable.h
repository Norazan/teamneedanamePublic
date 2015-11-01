#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include <SFML/Graphics.hpp>

class drawable {
public: 
	//drawable() = 0;
	virtual void draw(sf::RenderWindow &window, sf::Vector2f &pos) = 0;

};

#endif
#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include <SFML/Graphics.hpp>

class drawable {
public: 
	virtual void draw(sf::RenderWindow &window);
};

#endif
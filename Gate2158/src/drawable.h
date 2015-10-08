#ifndef _DRAWABLE_H
#define _DRAWABLE_H

#include <SFML/Graphics.hpp>

class drawable {
public: 
	drawable(sf::Vector2f pos);
	virtual void draw(sf::RenderWindow &window);
	virtual sf::Vector2f getSize();
	virtual float getRotation();
	virtual void setRotation(float rotation);
	void setPosition(sf::Vector2f pos);
	sf::Vector2f getPosition();
	
private:
	sf::Vector2f position;
};

#endif
//
// Created by martijn on 9/16/15.
//

#ifndef SFMLDEMO_RECTANGLE_HPP
#define SFMLDEMO_RECTANGLE_HPP

#include <SFML/Graphics.hpp>

class rectangle{
public:
    rectangle(sf::Vector2f dimensions, sf::Color color);
    void draw(sf::RenderWindow & window, sf::Vector2f position ) const;


private:
	sf::Vector2f dimensions;
	sf::Color color;

};

#endif //SFMLDEMO_RECTANGLE_HPP

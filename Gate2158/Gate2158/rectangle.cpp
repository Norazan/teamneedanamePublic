//
// Created by martijn on 9/16/15.
//

#include "rectangle.h"
#include <SFML/Graphics.hpp>

rectangle::rectangle(sf::Vector2f dimensions, sf::Color color):
color{ color },
dimensions{ dimensions }
{
}

void rectangle::draw(sf::RenderWindow & window, sf::Vector2f position) const{
    sf::RectangleShape rect;
    rect.setSize(dimensions);
    rect.setPosition(position);
    rect.setFillColor(color);
    window.draw(rect);
}
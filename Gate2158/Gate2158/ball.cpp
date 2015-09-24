//
// Created by martijn on 9/2/15.
//

#include "ball.h"
#include <SFML/Graphics.hpp>

ball::ball(sf::Vector2f position, float size):
position{ position },
size{ size }
{}

void ball::draw( sf::RenderWindow & window ) const{
    sf::CircleShape circle;
    circle.setRadius(size);
    circle.setPosition(position);
    window.draw(circle);
}

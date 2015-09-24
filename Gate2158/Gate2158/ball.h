//
// Created by martijn on 9/2/15.
//

#ifndef SFML_TEST_BALL_HPP
#define SFML_TEST_BALL_HPP
#include <SFML/Graphics.hpp>

class ball{
public:
    ball (sf::Vector2f position, float size = 30.0);
    void draw(sf::RenderWindow & window ) const;

private:
    sf::Vector2f position;
    float size;
};

#endif //SFML_TEST_BALL_HPP

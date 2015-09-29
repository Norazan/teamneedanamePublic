//
// Created by martijn on 9/29/15.
//

#ifndef GATE2158_CAMERA_HPP
#define GATE2158_CAMERA_HPP

#include <SFML/Graphics.hpp>


class Camera {
public:
	Camera(sf::RenderWindow & window);
private:
	sf::RenderWindow &window;
};


#endif //GATE2158_CAMERA_HPP

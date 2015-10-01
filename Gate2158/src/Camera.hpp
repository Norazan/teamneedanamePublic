//
// Created by martijn on 9/29/15.
//

#ifndef GATE2158_CAMERA_HPP
#define GATE2158_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Map.h"


class Camera {
public:
	Camera(sf::RenderWindow &window, Map &currentMap);
	void draw();
private:
	sf::RenderWindow &window;
	Map &currentMap;
};


#endif //GATE2158_CAMERA_HPP

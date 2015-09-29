//
// Created by martijn on 9/29/15.
//

#ifndef GATE2158_CAMERA_HPP
#define GATE2158_CAMERA_HPP

#include <SFML/Graphics.hpp>
#include "MapObject.h"


class Camera {
public:
	Camera(sf::RenderWindow &window);
	void updateMapObjects(std::vector<MapObject> &mapObjects);
	void draw();
private:
	sf::RenderWindow &window;
	std::vector<MapObject> &mapObjects{};
};


#endif //GATE2158_CAMERA_HPP

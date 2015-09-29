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
	void updateMapObjects();
	void draw();
private:
	sf::RenderWindow &window;
	std::vector<MapObject> &mapObjects{};
	Map &currentMap;
};


#endif //GATE2158_CAMERA_HPP

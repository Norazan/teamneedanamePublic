//
// Created by martijn on 10/27/15.
//

#include "Wall.h"
#include "Sprite.h"
#include <SFML/Graphics.hpp>

Wall::Wall(int lay, sf::Vector2f pos, drawable *drawable) :
MapObject{lay}
{
    renderLayer = lay;
    position = pos;
    drawObject = drawable;
	isFriendly = 4;

}

//
// Created by martijn on 10/27/15.
//

#include "Wall.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Wall::Wall(int lay, sf::Vector2f pos)
{
    static drawable *wallSprite;
    if(!wallSprite){
        wallSprite = new Sprite("../../Gate2158/media/textures/m-001.png");
    }
    renderLayer = lay;
    position = pos;
    drawObject = wallSprite;
	isFriendly = 4;

}

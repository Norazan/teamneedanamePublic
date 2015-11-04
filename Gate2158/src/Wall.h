//
// Created by martijn on 10/27/15.
//

#ifndef GATE2158_WALL_H
#define GATE2158_WALL_H


#include "MapObject.h"
#include "Sprite.h"
#include "drawable.h"

class Wall : public MapObject{
public:
    Wall(int renderLayer, sf::Vector2f position);

private:
    //static drawable *wallSprite;
};


#endif //GATE2158_WALL_H

//
// Created by martijn on 10/27/15.
//

#ifndef GATE2158_WALL_H
#define GATE2158_WALL_H


#include "MapObject.h"
#include "drawable.h"
/**
 * @brief A simple wall
 * @details A solid wall to bang your head against
 * 
 */
class Wall : public MapObject{
public:
	/**
	 * @brief The constructor for a simple wall object
	 * 
	 * @param renderLayer The layer the object should be rendered on
	 * @param position The position the object is placed
	 * @param drawable The drawable used to draw the wall
	 */
    Wall(int renderLayer, sf::Vector2f position, drawable *drawable);

private:
    //static drawable *wallSprite;
};


#endif //GATE2158_WALL_H

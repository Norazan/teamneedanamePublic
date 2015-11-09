/**
* @file World.h
* @author -
* @date -
* @version 1.0
*
* The Wold class is used to save and load levels.
*/

#ifndef GATE2158_WORLD_HPP
#define GATE2158_WORLD_HPP

#include "Map.h"

class World {
public:
	/**
	* Constructor that makes a empty wold
	*/
	World();
	/**
	* Returns the current map
	*
	* @return
	*		The current map
	*/
	Map& getCurrentMap();
	/**
	* Adds a map to the world
	*
	* @param m
	*		The map that will be added
	*/
	void addMap(Map &m);
	/**
	* Sets the world to the next map
	*/
	void nextMap();
	/**
	* Returns in which map the world is
	*
	* @return
	*		The number of the current map
	*/
	int getCurrentMapCount();
private:
	int currentMap = 0;		/** The number of the current map */
	Map maps[10];			/** A list of maps */
	int mapCount = 0;		/** The number of the total count of maps */
};


#endif //GATE2158_WORLD_HPP
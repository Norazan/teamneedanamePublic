/**
* @file Map.h
* @author Martijn
* @date 9/28/15
* @version 1.0
*
* The Map class to make map in the world
*/

#ifndef GATE2158_MAP_H
#define GATE2158_MAP_H

#include "Sprite.h"
#include "Rectangle.h"
#include "MapObject.h"
#include "UserCharacter.h"
#include <vector>

class UserCharacter;

class Map {
public:
	/**
	* Constructor that makes a empty map
	*/
    Map();
	/**
	* Constructor makes a empty map and makes the hitbox points
	*
	* @param layers
	*		The number of layers in the map
	*/
	Map(int layers);
	/**
	* Adds a MapObject to the map
	*
	* @param object
	*		The MapObject that will be added to the map
	*/
    void addMapObject(MapObject *object);
	/**
	* Will remove a list MapObjects of the map
	*
	* @param removeObject
	*		A list of objects that will be removed
	*/
	void removeMapObject(std::vector<MapObject*> removeObject);
	/**
	* Returns all MapObject of the map
	*
	* @return
	*		A list of all MapObjects of the map
	*/
	std::vector<MapObject*>& getAllMapObjects();
	/**
	* Returns all MapObject around the player
	*
	* @param pointA
	*		The top left corner of the window
	* @param pointB
	*		The bottom right corner of the window
	* @return
	*		A list of all MapObjects around the player
	*/
	std::vector<MapObject*>* getMapObjectsInRegion(sf::Vector2f pointA, sf::Vector2f pointB);
	/**
	* Returns the number of layers of the map
	*
	* @return
	*		The number of layers
	*/
	int getLayers();
	/**
	* Sets the number of layers of the map
	*
	* @param layers
	*		The number of layers
	*/
	void setLayers(int layers);
	/**
	* Loads the map by making MapObjects
	*
	* @param filname
	*		The path to the file
	*/
	void loadFromFile(std::string filename);
	/**
	* Returns the current player on the map
	*
	* @return
	*		The current player
	*/
	MapObject *getCurrentPlayer();
	/**
	* The player on the map as UserCharacter
	*/
	UserCharacter *player;
private:
	int layers;								/** The number of layers of the map */
	std::vector<MapObject*> mapObjects;		/** A list of MapObjects on the map */
	MapObject *currentPlayer;				/** The player on the map as MapObject */
	std::vector<sf::Vector2f> wall;			/** The points of the wall hitbox */
	std::vector<sf::Vector2f> enemyHit;		/** The points of the enemy hitbox */
	std::vector<sf::Vector2f> userHitbox;	/** The points of the player hitbox */
	std::vector<sf::Vector2f> finishHitbox;	/** The points of the finish hitbox */
	Convex *convexWall;						/** The convex of the wall */
	Convex *convexUser;						/** The convex of the player */
	Convex *convexEnemy;					/** The convex of the enemy */
	Convex *convexFinish;					/** The convex of the finish */
	Sprite *enemyShotgun;					/** The sprite of the enemy with a shotgun */
	Sprite *enemyPistol;					/** The sprite of the enemy with a pistol */
	Sprite *characterGunSprite;				/** The sprite of the player */
	Sprite *wallSprite;						/** The sprite of the wall */
	Sprite *finishSprite;					/** The sprite of the finish */
	Sprite *healthSprite;					/** The sprite of the healtPotion */
};


#endif //GATE2158_MAP_H

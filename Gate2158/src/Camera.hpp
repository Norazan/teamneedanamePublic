/**
* @file Camera.hpp
* @author Martijn
* @date 9/29/15
* @version 1.0
*
* The Camera class draws everything on the screen
* THE CAMERA CLASS IS A SINGLETON CLASS, so there can be only one camera.
*/

#ifndef GATE2158_CAMERA_H
#define GATE2158_CAMERA_H

#include <SFML/Graphics.hpp>
#include "MapObject.h"
#include "Map.h"
#include "UserCharacter.h"

class Map;

class Camera {
public:	
	/**
	* Gives the Camera class
	*
	* @return
	*		The only Camera class
	*/
	static Camera* getInstance(); 
	/**
	* Drawed all objects around the player
	* And the function act() of the MapObjects will be called
	*/
	void draw();
	/**
	* Add a MapObject to the current Map
	*
	* @param mo
	*		MapObject pointer that will be added to the current Map
	*/
	void addMapObjectToCurrentMap(MapObject *mo);
	/**
	* Removed a MapObject of the current Map
	*
	* @param mo
	*		MapObject pointer that will be removed of the current Map
	*/
	void revmoveMapObjectOnCurrentMap(MapObject *mo);
	/**
	* Gives all objects on the current map that are around the player
	*
	* @return
	*		A vector pointer of MapObject pointers
	*/
	std::vector<MapObject*> *getObjectsAroundPlayer();
	/**
	* Checked for all object around the player if they collide
	* If they collide, the collisonDetected funtion of the MapObjects will be called
	*/
	void checkCollision();
	/**
	* Sets the attribute window
	*
	* @param window
	*		The window where the camera will draw
	*/
	void setWindow(sf::RenderWindow &window);
	/**
	* Sets the attribute currentMap
	*
	* @param currenMap
	*		The map that will be drawed
	*/
	void setCurrentMap(Map & currentMap);
	/**
	* Sets the attribute currentPlayer
	*
	* @param currentPlayer
	*		The current player
	*/
	void setCurrentPlayer(MapObject *currentPlayer);
	/** 
	* The window where the camera will draw 
	*/
	sf::RenderWindow *window;
	/**
	* Boolean if game is ended
	*/
	bool endGame = false;
	/**
	* Boolean if next level
	*/
	bool nextLevel = false;
private:
	/**
	* Constructor of Camera
	*/
	Camera();
	/**
	* The camera class
	*/
	static Camera *camera;
	/**
	* The map that will be drawed
	*/
	Map *currentMap;
	/**
	* The current player to sets the draw positions
	*/
	MapObject *currentPlayer;
	/**
	* A list of MapObjects that will be removed of the map afther the draw.
	*/
	std::vector<MapObject*> removeObjects;
	/**
	* A list of MapObjects that will be added to the map afther the draw.
	*/
	std::vector<MapObject*> addObjects;
	/**
	* A list of MapObjects that are around the player.
	*/
	std::vector<MapObject*> *objectsAroundPlayer;
};

#endif //GATE2158_CAMERA_HPP

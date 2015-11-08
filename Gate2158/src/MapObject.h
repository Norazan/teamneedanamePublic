/**
* @file MapObject.h
* @author Martijn
* @date 9/28/15
* @version 1.0
*
* The MapObject class to make MapObjects on the map
*/

#ifndef GATE2158_MAPOBJECT_H
#define GATE2158_MAPOBJECT_H


#include <SFML/Graphics.hpp>
#include "drawable.h"
#include "Convex.h"

class MapObject {
public:
	/**
	* Constructor that makes a empty MapObject
	*/
	MapObject();
	/**
	* Constructor that makes a empty MapObject used to make bullets
	*
	* @param renderLayer
	*		The layer where the MapObject will be drawed
	*/
	MapObject(int renderLayer);
	/**
	* Constructor that sets the variable of the MapObject.
	*
	* @param renderLayer
	*		The layer on where the MapObject will be drawed
	* @param drawable
	*		The drawable that will be drawed
	* @param position
	*		The position on the map
	*/
	MapObject(int renderLayer, drawable* drawable, sf::Vector2f position);
	/**
	* Constructor that sets the variable of the MapObject.
	*
	* @param renderLayer
	*		The layer on where the MapObject will be drawed
	* @param drawable
	*		The drawable that will be drawed
	* @param position
	*		The position on the map
	* @param convex
	*		The hitbox of the MapObject
	*/
	MapObject(int renderLayer, drawable* drawables, sf::Vector2f position, Convex* hitbox);
	/**
	* Will rotate the drawable of the MapObject
	*
	* @param rotation
	*		The rotation where the drawable will rotate to in degrees
	*/
	void rotate(float rotation);
	/**
	* Returns the roation of the drawable
	*
	* @return
	*		The rotation where the drawable is rotated to in degrees
	*/
    float getRotation();
	/**
	* Sets the postion of the MapObject on the map
	*
	* @param pos
	*		The position that will be set
	*/
	void setPosition(sf::Vector2f pos);
	/**
	* Returns the position of the MapObject on the map
	*
	* @return
	*		The position of the MapObject on the map
	*/
	sf::Vector2f getPosition();
	/**
	* Sets the renderLayer of the MapObject
	*
	* @param renderLayer
	*		The renderLayer that will be set
	*/
	void setRenderLayer(int renderLayer);
	/**
	* Returns the renderLayer of the MapObject
	*
	* @return
	*		The renderLayer of the MapObject
	*/
	int getRenderLayer();
	/**
	* Returns the size of the drawable
	*
	* @return
	*		The size of the drawable
	*/
	sf::Vector2f getSize();
	/**
	* Calculate the rotated points of the hitbox, and returns them.
	* If there is no hitbox, it will make a square one of the drawable (without rotation).
	*
	* @return
	*		The rotatated points of the hitbox
	*/
	std::vector<sf::Vector2f> getConvexPoints();
	/**
	* Returns the origin of the hitbox
	*
	* @return
	*		The origin of the hitbox
	*/
	sf::Vector2f getOrigin();
	/**
	* Returns the earned expoints on hit
	*
	* @param damage
	*		The damage to calculate the earned expoints
	* @return
	*		The earned expoints
	*/
	virtual int getExpoints(int damage);
	/**
	* Sets damage to the MapObject
	*
	* @param damage
	*		The damage
	*/
	virtual void setDamage(int damage);
	/**
	* All the activities that the MapObject will do before drawing
	*
	* @param window
	*		The window where the activities take place
	*/
	virtual void act(sf::RenderWindow & window);
	/**
	* Draws the MapObject on the screen
	*
	* @param window
	*		The window where the MapObject will be drawed
	* @param drawPosition
	*		The position on the screen where the MapObject will be drawed
	*/
	virtual void draw(sf::RenderWindow & window, sf::Vector2f drawPosition);
	/**
	* Sets the hitbox of the MapObject
	*
	* @param Hitbox
	*		The hibox that will be set
	*/
	void setHitbox(Convex *Hitbox);
	/**
	* Returns the hitbox of the MapObject
	*
	* @return
	*		The hibox of the MapObject
	*/
	Convex* getHitbox();
	/**
	* What to do when a MapObject collide is described in the other classes
	*
	* @param mo
	*		The MapObject where the MapObject has collide with.
	*/
	virtual void collisionDetected(MapObject & mo);
	/**
	* Sets the draw postion of the MapObject
	*
	* @param drawPos
	*		The draw position that will be set
	*/
	void setDrawPosition(sf::Vector2f drawPos);
	/**
	* Returns the draw postion of the MapObject
	*
	* @return
	*		The draw position of the MapObject
	*/
	sf::Vector2f getDrawPosition();
	/**
	* Sets the maximum health of the MapObject (only useful on characters)
	*/
	virtual void setMaxHealth();	
	/** 
	* Returns the friendly number
	* 
	* @return
	*		The friendly number of the MapObject
	*/
	int isFriend();						
private:
	Convex* Hitbox = nullptr;			/** The hitbox of the MapObject */	

protected:
	drawable *drawObject;				/** The drawable of the MapObject */
	int renderLayer;					/** The renderLayer of the MapObject */
	int totalExpoints = 0;				/** The totale expoints of the Map Object */
	sf::Vector2f position;				/** The position of the MapObject on the map */
	sf::Vector2f drawPosition;			/** The position of the MapObject on the window */
	int isFriendly = 0;					/** Number that is used to show who shot the bullet */
};


#endif //GATE2158_MAPOBJECT_H

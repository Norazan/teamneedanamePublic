//
// Created by martijn on 9/28/15.
//

#include "MapObject.h"
#include <iostream>

MapObject::MapObject(){
	
}

MapObject::MapObject(int renderLayer, drawable* drawable) :
	renderLayer{ renderLayer },
	drawObject{ drawable }
{
	
}

MapObject::MapObject(int renderLayer, drawable* drawable, Convex * hitbox) :
	renderLayer{ renderLayer },
	drawObject{ drawable },
	Hitbox{hitbox}
{

}

MapObject::MapObject(int renderLayer) :
	renderLayer{ renderLayer }
{
	
}

void MapObject::rotate(float rotation) {
	if (Hitbox != nullptr){
		Hitbox->setRotation(rotation);
	}
	if (drawObject != nullptr){
		drawObject->setRotation(rotation);
	}
}

float MapObject::getRotation() {
	if (drawObject != nullptr){
		return drawObject->getRotation();
	}
	else {
		return 0;
	}
}


void MapObject::setPosition(sf::Vector2f pos){
	if (Hitbox != nullptr){
		Hitbox->setPosition(pos);
	}
	if (drawObject != nullptr){
		drawObject->setPosition(pos);
	}
}

sf::Vector2f MapObject::getPosition(){
	if (drawObject != nullptr){
		return drawObject->getPosition();
	}
	else {
		return sf::Vector2f{ 0, 0 };
	}
}

void MapObject::setRenderLayer(int renderLayer){
	this->renderLayer = renderLayer;
}

int MapObject::getRenderLayer(){
	return renderLayer;
}

std::vector<sf::Vector2f> MapObject::getConvexPoints(){
	if (Hitbox != nullptr){
		std::vector<sf::Vector2f> points = Hitbox->getPoints();
		for (auto & point : points){
			point = Hitbox->getPosition() + point;
		}
		//Add rotation to ConvexPoints
		float rotationAngle = getRotation();

		std::vector<sf::Vector2f> rotatedPoints;
		sf::Vector2f origin = Hitbox->getOrigin() + Hitbox->getPosition();

		for (auto &p : points){

			float deltaX = p.x - origin.x;
			float deltaY = p.y - origin.y;

			float length = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

			float deltaAngle = abs(atan(deltaX / deltaY));
			deltaAngle = float(deltaAngle * (360 / (2 * 3.14159265359)));
			float pointAngle = 0;

			if (p.x > origin.x && p.y < origin.y){ // 1
				pointAngle = deltaAngle;
			}
			else if ((p.x < origin.x && p.y < origin.y) || (p.y == origin.y && p.x < origin.x)){ // 2
				pointAngle = deltaAngle + 90;
			}
			else if (p.x < origin.x && p.y > origin.y){ // 3
				pointAngle = deltaAngle + 180;
			}
			else if (p.x > origin.x && p.y > origin.y){ // 4
				pointAngle = deltaAngle + 270;
			}

			//float x = cos(float((360 - rotationAngle + pointAngle)*(360 / (2 * 3.14159265359)))) * length;
			//float y = sin(float((360 - rotationAngle + pointAngle)*(360 / (2 * 3.14159265359)))) * length;
			float x = (float)(length * cos((rotationAngle + pointAngle) * 3.14159265359 / 180)) + origin.x;
			float y = (float)(length * sin((rotationAngle + pointAngle) * 3.14159265359 / 180)) + origin.y;
			

			rotatedPoints.push_back(sf::Vector2f(x, y));
		}
		return rotatedPoints;
	}
	else {
		std::vector<sf::Vector2f> nultje{ sf::Vector2f{ 0, 0 } };
		std::vector<sf::Vector2f> &nul = nultje;
		return nul;
	}
}

void MapObject::draw(sf::RenderWindow & window){
	if (Hitbox != nullptr){
		Hitbox->draw(window);
	}
	drawObject->draw(window);
}
sf::Vector2f MapObject::getSize(){
	if (drawObject != nullptr){
		return drawObject->getSize();
	}
	else {
		return sf::Vector2f{ 0, 0 };
	}
}

void MapObject::setHitbox(Convex * Hitbox){
	MapObject::Hitbox = Hitbox;
}

Convex* MapObject::getHitbox(){
	return Hitbox;
}

sf::Vector2f MapObject::getOrigin(){
	return Hitbox->getOrigin();
}

void MapObject::collisionDetected(MapObject & mos){

}
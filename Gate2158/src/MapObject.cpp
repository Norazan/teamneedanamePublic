//
// Created by martijn on 9/28/15.
//


#define PI 3.14159265

#include "MapObject.h"
#include <iostream>

MapObject::MapObject(){
	
}

MapObject::MapObject(int renderLayer, drawable *drawable, sf::Vector2f position):
	renderLayer{renderLayer},
	drawObject{ drawable },
	position{ position }
{
	position = sf::Vector2f{ 0, 0 };
	isFriendly = false;
}

MapObject::MapObject(int renderLayer, drawable* drawable, sf::Vector2f position, Convex * hitbox) :
	renderLayer{ renderLayer },
	drawObject{ drawable },
	position{ position },
	Hitbox{hitbox}
{
	isFriendly = false;
}

MapObject::MapObject(int renderLayer) :
	renderLayer{ renderLayer }
{
	position = sf::Vector2f{ 0, 0 };
	isFriendly = false;
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
	
}

sf::Vector2f MapObject::getPosition(){
	return position;
}

void MapObject::setRenderLayer(int renderLayer){
	this->renderLayer = renderLayer;
}

int MapObject::getRenderLayer(){
	return this->renderLayer;
}

std::vector<sf::Vector2f> MapObject::getConvexPoints(){
	if (Hitbox != nullptr){

		sf::Vector2f size = Hitbox->getSize();
		sf::Vector2f pos = drawPosition;
		pos.x += ((size.x - 90) / 10) * -5;
		pos.y += ((size.y - 50) / 10) * -5;

		std::vector<sf::Vector2f> points = Hitbox->getPoints();
		for (auto & point : points){
			point = pos + point;
		}
		//Add rotation to ConvexPoints
		float rotationAngle = getRotation();

		std::vector<sf::Vector2f> rotatedPoints;
		sf::Vector2f origin = Hitbox->getOrigin() + pos;

		for (auto &p : points){

			float deltaX = p.x - origin.x;
			float deltaY = p.y - origin.y;

			float length = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

			float deltaAngle = abs(atan(deltaX / deltaY));
			deltaAngle = float(deltaAngle * (360 / (2 * PI)));
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
			float x = (float)(length * cos((rotationAngle + pointAngle) * PI / 180)) + origin.x;
			float y = (float)(length * sin((rotationAngle + pointAngle) * PI / 180)) + origin.y;
			

			rotatedPoints.push_back(sf::Vector2f(x, y));
		}
		return rotatedPoints;
	}
	else {
		std::vector<sf::Vector2f> points;
		sf::Vector2f pos = drawPosition;
		sf::Vector2f size;
		if (drawObject != nullptr){
			size = drawObject->getSize();
		}
		else {
			size = sf::Vector2f{ 10, 10 };
		}
		pos.x += ((size.x - 90) / 10) * -5; 
		pos.y += ((size.y - 50) / 10) * -5;
		points.push_back(sf::Vector2f{ pos.x, pos.y });
		points.push_back(sf::Vector2f{ pos.x + size.x, pos.y });
		points.push_back(sf::Vector2f{ pos.x + size.x, pos.y + size.y });
		points.push_back(sf::Vector2f{ pos.x, pos.y + size.y });
		return points;
	}
}

void MapObject::draw(sf::RenderWindow & window, sf::Vector2f drawPosition){
	if (Hitbox != nullptr){
		Hitbox->draw(window, drawPosition);
	}
	drawObject->draw(window, drawPosition);
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

int MapObject::isFriend(){
	return isFriendly;
}

void MapObject::collisionDetected(MapObject & mos){

}

int MapObject::getExpoints(int damage){
	return totalExpoints;
}

void MapObject::act(sf::RenderWindow & window){

}

void MapObject::setDamage(int damage){

}

void MapObject::setDrawPosition(sf::Vector2f drawPos){
	drawPosition = drawPos;
}
sf::Vector2f MapObject::getDrawPosition(){
	return drawPosition;
}

//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MAPOBJECT_H
#define GATE2158_MAPOBJECT_H


#include <SFML/System/Vector2.hpp>

class MapObject {
public:
    void setAngle(float angle);
    float getAngle();
private:
    sf::Vector2f position;
    unsigned int colorCode;
    bool isSolid;
    float angle;
};


#endif //GATE2158_MAPOBJECT_H
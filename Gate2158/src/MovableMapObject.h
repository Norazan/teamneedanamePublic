//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_MOVABLEMAPOBJECT_H
#define GATE2158_MOVABLEMAPOBJECT_H

#include "MapObject.h"

class MovableMapObject : public MapObject {
public:
    void setVelocity(float v);
    float getVelocity();

private:
    float velocity;
};


#endif //GATE2158_MOVABLEMAPOBJECT_H

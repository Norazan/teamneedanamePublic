//
// Created by martijn on 9/28/15.
//

#ifndef GATE2158_CHARACTER_H
#define GATE2158_CHARACTER_H


#include "MovableMapObject.h"

class Character : public MovableMapObject {
public:
    float getHealth(void);
    void setHealth(float h);

private:
    float health;
    float maxHealth;
};


#endif //GATE2158_CHARACTER_H

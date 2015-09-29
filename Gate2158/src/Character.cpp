//
// Created by martijn on 9/28/15.
//

#include "Character.h"

Character::Character(float maxHealth):
	maxHealth{maxHealth}
{

}

float Character::getHealth(void) {
    return 0;
}

void Character::setHealth(float h) {
    health = h;
}

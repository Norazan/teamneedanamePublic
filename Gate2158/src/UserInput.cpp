//
// Created by Thijs on 9/29/15.
//

#include "UserInput.h"

bool UserInput::getPressed(char key) {
	if (key == 'w') {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
			return 1;
		}
	}
	if (key == 'a') {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
			return 1;
		}
	}
	if (key == 's') {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
			return 1;
		}
	}
	if (key == 'd') {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
			return 1;
		}
	}
	return 0;
}
//
// Created by Thijs on 9/29/15.
//

#include "UserInput.h"

bool UserInput::getPressed(char key){

	int keyRequested = (int)key - (int)'a';

	if (sf::Keyboard::isKeyPressed((sf::Keyboard::Key)keyRequested)) {
		return 1;
	}

	return 0;
}

bool UserInput::getPressed(sf::Keyboard::Key key){

	if (sf::Keyboard::isKeyPressed(key)){
		return 1;
	}

	return 0;
}

bool UserInput::getMousePress(sf::Mouse::Button mouseButton){

	if (sf::Mouse::isButtonPressed(mouseButton)){
		return 1;
	}

	return 0;
}

sf::Vector2i UserInput::getMousePosition(sf::RenderWindow &window){
	return sf::Mouse::getPosition(window);
}

void UserInput::setToggleKey(sf::Keyboard::Key key){
	MyToggleKey k1;
	k1.key = key;
	k1.currentState = getPressed(key);
	k1.pressed = false;
	k1.hold = false;
	k1.pressedState = false;

	keyToggleList.push_back(k1);
}

bool UserInput::getToggleKey(sf::Keyboard::Key key){
	for (std::vector<MyToggleKey>::iterator it = keyToggleList.begin(); it !=keyToggleList.end(); it++)
	{
		if (it->key == key){
			return it->currentState;
		}
	}

	return false;
}

void UserInput::updateToggleKey(){
	for (std::vector<MyToggleKey>::iterator it = keyToggleList.begin(); it != keyToggleList.end(); it++)
	{
		it->currentState = getPressed(it->key);

		if (it->currentState == true && it->pressed == false && it->hold == false){
			it->pressed = true;
			it->hold = true;
		}

		if (it->currentState == false){
			it->pressed = false;
			it->hold = false;
		}
	}
}

bool UserInput::isKeyPressed(sf::Keyboard::Key key){
	for (std::vector<MyToggleKey>::iterator it = keyToggleList.begin(); it != keyToggleList.end(); it++)
	{
		if ((it->key == key) && (it->pressed)){
			it->pressed = false;
			return true;
		}
	}
	return false;
}

bool UserInput::isKeyHold(sf::Keyboard::Key key){
	for (std::vector<MyToggleKey>::iterator it = keyToggleList.begin(); it != keyToggleList.end(); it++)
	{
		if ((it->key == key) && (it->pressed)){
			return it->hold;
		}
	}
	return false;
}


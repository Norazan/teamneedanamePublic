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
	k1.previousState = false;

	keyToggleList.push_back(k1);
}

bool UserInput::getToggleKey(sf::Keyboard::Key){
	for (std::vector<MyToggleKey>::iterator it = keyToggleList.begin(); it !=keyToggleList.end(); it++)
	{
		
	}
}

void UserInput::updateToggleKey(){
	
}

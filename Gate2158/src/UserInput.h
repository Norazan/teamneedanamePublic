//
// Created by Thijs on 9/29/15.
//

#ifndef GATE2158_USERINPUT_H
#define GATE2158_USERINPUT_H

#include <SFML/Graphics.hpp>
#include <vector>

struct MyToggleKey{
	sf::Keyboard::Key key;
	bool pressed;
	bool hold;
	bool pressedState;
	bool currentState;
};

class UserInput{
public:
	bool getPressed(char key);
	bool getPressed(sf::Keyboard::Key);
	bool getMousePress(sf::Mouse::Button);
	sf::Vector2i getMousePosition(sf::RenderWindow &window);
	bool getToggleKey(sf::Keyboard::Key);
	void setToggleKey(sf::Keyboard::Key);
	bool isKeyPressed(sf::Keyboard::Key);
	bool isKeyHold(sf::Keyboard::Key);
	void updateToggleKey();
private:
	std::vector<MyToggleKey> keyToggleList;
};




#endif //GATE2158_USERINPUT_H
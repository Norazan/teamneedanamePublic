/**
* @file UserInput.h
* @author Thijs
* @date 9/29/15
* @version 1.0
*
* The UserInput class to check user input.
*/

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
	/**
	* Checks if a key is pressed 
	*
	* @param key
	*		A char of the key that will be checked
	* @return
	*		A boolean if the key is pressed
	*/
	bool getPressed(char key);
	/**
	* Checks if a key is pressed
	*
	* @param key
	*		The key that will be checked
	* @return
	*		A boolean if the key is pressed
	*/
	bool getPressed(sf::Keyboard::Key);
	/**
	* Checks if a the mouse is pressed
	*
	* @param key
	*		The mouse key that will be checked
	* @return
	*		A boolean if the mouse key is pressed
	*/
	bool getMousePress(sf::Mouse::Button);
	/**
	* Returns the mouse position
	*
	* @param window
	*		The window where the mouse is
	* @return
	*		The position of the mouse
	*/
	sf::Vector2i getMousePosition(sf::RenderWindow &window);
	/**
	* Check if key is in the list of the ToggleKeys
	*
	* @param key
	*		The key that wil checked
	* @return
	*		A boolean if the key is present in the list
	*/
	bool getToggleKey(sf::Keyboard::Key);
	/**
	* Sets a key to the ToggleKey list (used to checked also if the key is hold)
	*
	* @param key
	*		The key that will be add
	*/
	void setToggleKey(sf::Keyboard::Key);
	/**
	* Check if key is pressed (key needs to be in the ToggleKey list)
	*
	* @param key
	*		The key that wil checked
	* @return
	*		A boolean if the key is pressed
	*/
	bool isKeyPressed(sf::Keyboard::Key);
	/**
	* Check if key is hold (key needs to be in the ToggleKey list)
	*
	* @param key
	*		The key that wil checked
	* @return
	*		A boolean if the key is hold
	*/
	bool isKeyHold(sf::Keyboard::Key);
	/**
	* Update the ToggleKeys, by checking if the key is hold or released
	*/
	void updateToggleKey();
private:
	std::vector<MyToggleKey> keyToggleList;		/** The list of ToggleKeys */
};




#endif //GATE2158_USERINPUT_H
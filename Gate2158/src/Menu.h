/**
* @file Menu.h
* @author Christiaan
* @date -
* @version 1.0
*
* The Menu class show the menu, before the game start
*/

#ifndef GATE2158_MENU_H
#define GATE2158_MENU_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UserInput.h"

class Menu{
public:
	/**
	* Constructor that sets the variable of the MapObject.
	*
	* @param windowRef
	*		The window where the menu will be drawed
	* @param showMenu
	*		A boolean if the menu has to be showed
	*/
	Menu(sf::RenderWindow &windowRef, bool showMenu);
	/**
	* Drawed the splashscreen if the boolean splashScreen is true. 
	* If the boolean is false it draws the menu.
	*/
	void draw();
	/**
	* Check if there is input of the user, and proccesed this.
	*/
	void processKeys();
	/**
	* Returns if the menu is showing or not
	*
	* @return
	*		Boolean showingMenu
	*/
	bool getShowingMenu();
private:
	sf::RenderWindow &window;								/** The window where the menu will be drawed */
	bool showingMenu;										/** A boolean if the menu needs to be drawed */
	int currentSelection;									/** A number which button is selected */
	bool splashScreen;										/** A boolean if the splashscreen needs to be drawed */
	UserInput input;										/** The input to check if a button is pressed */
	sf::Vector2f startLocation{ 1280 / 2 - 200 / 2, 400 };	/** The position of the start button on the screen */
	sf::Vector2f quitLocation{ 1280 / 2 - 200 / 2, 550 };	/** The position of the quit button on the screen */
	sf::Texture gameLogoTexture;							/** The Texture of the logo on the menu */
	sf::Texture logoTexture;								/** The Texture of the logo on the splahscreen */
	sf::Texture startTexture;								/** The Texture of the start button */	
	sf::Texture quitTexture;								/** The Texture of the quit button */
	sf::Music menuBackgroundMusic;							/** The Music that wil be played while showing the menu */
};


#endif
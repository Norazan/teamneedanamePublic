#include "Menu.h"
#include <iostream>
Menu::Menu(sf::RenderWindow &windowRef, bool showMenu)
: window(windowRef),
showingMenu(showMenu),
currentSelection(0),
splashScreen(true)
{
	input.setToggleKey(sf::Keyboard::Up);
	input.setToggleKey(sf::Keyboard::Down);
	input.setToggleKey(sf::Keyboard::Space);
	input.setToggleKey(sf::Keyboard::Return);
}

void Menu::draw(){
	input.updateToggleKey();
	showingMenu = true;
	sf::Texture gameLogoTexture;
	sf::Texture logoTexture;
	sf::Texture startTexture;
	sf::Texture quitTexture;
	if (!logoTexture.loadFromFile("../../Gate2158/media/TEAMNEEDSANAME.png")){
	}
	if (!startTexture.loadFromFile("../../Gate2158/media/GameStart.png")){
	}
	if (!quitTexture.loadFromFile("../../Gate2158/media/GameStop.png")){
	}
	if (!gameLogoTexture.loadFromFile("../../Gate2158/media/GameLogo.png")){
	}
	sf::Sprite splashLogo;
	splashLogo.setTexture(logoTexture);
	splashLogo.setPosition(sf::Vector2f(1280 / 2 - 500 / 2, 720 / 2 - 380 / 2));

	sf::Sprite gameLogo;
	gameLogo.setTexture(gameLogoTexture);
	gameLogo.setPosition(sf::Vector2f(1280 / 2 - 500 / 2, 0));

	sf::Sprite start;
	start.setTexture(startTexture);
	start.setPosition(startLocation);
	sf::Sprite quit;
	quit.setTexture(quitTexture);
	quit.setPosition(quitLocation);
	sf::CircleShape select1(20);
	sf::CircleShape select2(20);
	select1.setFillColor(sf::Color::White);
	select2.setFillColor(sf::Color::White);
	if (showingMenu){
		processKeys();
		if (currentSelection == 0){
			select1.setPosition(1280 / 2 - 200, 425);
			select2.setPosition(1280 / 2 + 150, 425);
		}
		else if (currentSelection == 1){
			select1.setPosition(1280 / 2 - 200, 575);
			select2.setPosition(1280 / 2 + 150, 575);
		}
		if (splashScreen){
			window.draw(splashLogo);
		}
		else{
			window.draw(gameLogo);
			window.draw(start);
			window.draw(quit);
			window.draw(select1);
			window.draw(select2);
		}
	}
}

void Menu::processKeys(){
	if (splashScreen){
		if (input.isKeyHold(sf::Keyboard::Space)){
			splashScreen = false;
		}
	}
	else{
		if (input.isKeyHold(sf::Keyboard::Up)){
			currentSelection = 0;
			std::cout << "Up";
		}
		else if (input.isKeyHold(sf::Keyboard::Down)){
			currentSelection = 1;
			std::cout << "down";
		}
		else if (input.isKeyHold(sf::Keyboard::Return)){
			if (currentSelection == 0){
				showingMenu = false;
			}
			else{
				window.close();
			}
		}

		else if (input.getMousePress(sf::Mouse::Left)){
			std::cout << "x: " << input.getMousePosition(window).x << " y:" << input.getMousePosition(window).y << "\n";
			if (input.getMousePosition(window).x >= startLocation.x && input.getMousePosition(window).x <= startLocation.x + 200 &&
				input.getMousePosition(window).y >= startLocation.y && input.getMousePosition(window).y <= startLocation.y + 100){
				showingMenu = false;
				std::cout << "false";
			}
			else if (input.getMousePosition(window).x >= quitLocation.x && input.getMousePosition(window).x <= quitLocation.x + 200 &&
				input.getMousePosition(window).y >= quitLocation.y && input.getMousePosition(window).y <= quitLocation.y + 100){
				window.close();
			}
		}
	}
}

bool Menu::getShowingMenu(){
	return showingMenu;
}
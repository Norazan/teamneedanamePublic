// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
//#include "World.h"
//#include "Map.h"
//#include "Camera.hpp"
//
//int main()
//{
//	sf::RenderWindow window(sf::VideoMode(400, 400), "Gate2158");
//	sf::RectangleShape rec0(sf::Vector2f{ 30.0, 30.0 });
//	sf::RectangleShape rec1(sf::Vector2f{ 40.0, 40.0 });
//	rec1.setFillColor(sf::Color::Blue);
//	MapObject rectangle0(0, rec0);
//	MapObject rectangle1(1, rec1);
//
//	Map testMap(2);
//    
//	testMap.addMapObject(rectangle0);
//	testMap.addMapObject(rectangle1);
//
//	World Gate2158;
//	Gate2158.addMap(testMap);
//	Map &currentMap = Gate2158.getCurrentMap();
//	Camera userCamera(window, currentMap);
//
//    window.setVerticalSyncEnabled(true);
//
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
#include "UserInput.h"
//#include "UserCharacter.h"
#include "Menu.h"
#include "World.h"
#include "Map.h"
#include "Camera.hpp"
#include "Rectangle.h"
#include "Sprite.h"
#include "Text.h"
#include "Circle.h"
#include "Character.h"
#include "UserCharacter.h"
#include <iostream>

int main()
{
	int width= 1280;
	int height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "Gate2158");
	//UserCharacter player = UserCharacter({ 25, 25 }, {200, 200}, sf::Color::Magenta);
	//player.draw(window);
	UserInput userInputKey;
	Menu menuScreen(window, true);

	//Rectangle rec0(sf::Vector2f{ 50.0, 50.0 }, sf::Vector2f{ 30.0, 30.0 }, sf::Color::Blue);
	//Rectangle rec1(sf::Vector2f{ 50.0, 50.0 }, sf::Vector2f{ 40.0, 40.0 }, sf::Color::Red);
	//Sprite testSprite(sf::Vector2f{ 200.0, 100.0 }, "../../Gate2158/media/download.jpg");
	//Sprite characterNormal(sf::Vector2f{ 200.0, 100.0 }, "../../Gate2158/media/character_normal.png");
	//Sprite characterGun(sf::Vector2f{ 300.0, 100.0 }, "../../Gate2158/media/character_gun.png");
	//Sprite characterShotgun(sf::Vector2f{ 200.0, 200.0 }, "../../Gate2158/media/character_shotgun.png");
	//Sprite characterMachineGun(sf::Vector2f{ 300.0, 200.0 }, "../../Gate2158/media/character_machinegun.png");
	//Circle circle(sf::Vector2f{ 100.0, 300.0 }, 30, sf::Color::Blue);
	
	//Character character(100, 0, &rec0);
	//UserCharacter userCharacter0(100, 3, &characterNormal);
	//UserCharacter userCharacter1(100, 3, &characterGun);
	//UserCharacter userCharacter2(100, 3, &characterMachineGun);
	//UserCharacter userCharacter3(100, 3, &characterShotgun);

	sf::Font tFont;

	if (!tFont.loadFromFile("../../Gate2158/media/Another_America.ttf")){
		//Error handeling
	}

	sf::String ttString("Test string");
	//Always pass the font by reference, they are heavy elements! 
	//Passing nby value will give a C++ exception error
	//Loading font should be a function in the Text object, maybe load minimal amount of fonts on game startup?
	//Text testText(ttString, sf::Vector2f(200, 200), sf::Text::Style::Regular, sf::Color::Red, 30, &tFont);

	//MapObject picture(3, &testSprite);
	//MapObject rectangle0(0, &rec0);
	//MapObject rectangle1(1, &rec1);
	//MapObject text(2, &testText);
	//MapObject circle0(2, &circle);


	//Map testMap(3);
    
	//testMap.addMapObject(character);
	//testMap.addMapObject(rectangle1);
	//testMap.addMapObject(&userCharacter0);
	//testMap.addMapObject(&userCharacter1);
	//testMap.addMapObject(&userCharacter2);
	//testMap.addMapObject(&userCharacter3);
	//testMap.addMapObject(text);
	//testMap.addMapObject(circle0);

	//World Gate2158;
	//Gate2158.addMap(testMap);
	//Map &currentMap = Gate2158.getCurrentMap();
	//Camera userCamera(window, currentMap);

    window.setVerticalSyncEnabled(true);

	//userInputKey.setToggleKey(sf::Keyboard::W);
	//userInputKey.setToggleKey(sf::Keyboard::S);

	while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
			if (event.type == sf::Event::Resized){
				height = event.size.height;
				width = event.size.width;
			}
        }


		//std::cout << userInputKey.getToggleKey(sf::Keyboard::W);

		userInputKey.updateToggleKey();



		/*
		//if (userInputKey.getPressed('w')){
		if (userInputKey.isKeyPressed(sf::Keyboard::W)){
			if (menuScreen.getCurrentSelection() == 1){
				menuScreen.setCurrentSelection(2);
			}
			else{
				menuScreen.setCurrentSelection(1);
			}
		}
		else if (userInputKey.getPressed('s')){
		//else if (userInputKey.isKeyPressed(sf::Keyboard::S)){
			if (menuScreen.getCurrentSelection() == 2){
				menuScreen.setCurrentSelection(1);
			}
			else{
				menuScreen.setCurrentSelection(2);
			}
		}
		else if (userInputKey.getPressed('a')){
			menuScreen.skipSplashScreen();
		}
		else if (userInputKey.getPressed('d')){
			if (menuScreen.getCurrentSelection() == 2){
				window.close();
			}
			else if (menuScreen.getCurrentSelection() == 1){
				// game start
			}
		}

		if (userInputKey.getMousePress(sf::Mouse::Left)){
			std::cout << "\nx: " << userInputKey.getMousePosition(window).x << "y: " << userInputKey.getMousePosition(window).y;
		}
		*/
        window.clear();
		if (menuScreen.getShowingMenu()){
			menuScreen.draw();
		}
		else{
			//userCamera.draw();
			//player.draw(window);
			//userCharacter.draw(window);
		}
        window.display();
    }
    return 0;
}

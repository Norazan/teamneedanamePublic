// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "UserInput.h"
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
#include "Convex.h"
#include <iostream>


int main()
{

	int width= 1280;
	int height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "Gate2158");
	Menu menuScreen(window);
	UserInput userInputKey;

	Rectangle rec0(sf::Vector2f{ 250.0, 250.0 }, sf::Vector2f{ 30.0, 30.0 }, sf::Color::Blue);
	Rectangle rec1(sf::Vector2f{ 50.0, 50.0 }, sf::Vector2f{ 30, 30 }, sf::Color::Red);
	Sprite testSprite(sf::Vector2f{ 200.0, 100.0 }, "../../Gate2158/media/download.jpg");
	Sprite characterGun(sf::Vector2f{ 300.0, 100.0 }, "../../Gate2158/media/character_gun.png");
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
	Text testText(ttString, sf::Vector2f(200, 200), sf::Text::Style::Regular, sf::Color::Red, 30, &tFont);

	//MapObject picture(3, &testSprite);
	//MapObject rectangle0(0, &rec0);
	MapObject rectangle1(1, &rec1);
	//MapObject text(2, &testText);
	//MapObject circle0(2, &circle);


	Map testMap(3);

	std::vector<sf::Vector2f> points{ 
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 30, 0 },
		sf::Vector2f{ 30, 30 },
		sf::Vector2f{ 0, 30 }
	};

	std::vector<sf::Vector2f> userHitbox{
		sf::Vector2f{ 0	, 0 },
		sf::Vector2f{ 50, 0 },
		sf::Vector2f{ 50, 50},
		sf::Vector2f{ 0	, 50 }
	};
	Convex convex(points, sf::Vector2f(250, 250), sf::Vector2f(15, 15));
	Convex convex2(points, sf::Vector2f(50, 50), sf::Vector2f(15, 15));
	Convex userHit(userHitbox, sf::Vector2f(300, 100), sf::Vector2f(25,25));
	
	//sf::ConvexShape convex1;
	/*convex1.setPosition(sf::Vector2f(200, 200));
	convex1.setPointCount(5);
	convex1.setPoint(0, sf::Vector2f(0, 0));
	convex1.setPoint(1, sf::Vector2f(150, 10));
	convex1.setPoint(2, sf::Vector2f(120, 90));
	convex1.setPoint(3, sf::Vector2f(30, 100));
	convex1.setPoint(4, sf::Vector2f(0, 50));*/

	MapObject con1(1, &rec0, &convex);
	MapObject con3(1, &rec1, &convex2);
	UserCharacter con2(100, 0, &characterGun, &userHit);

	//testMap.addMapObject(&rectangle1);
	testMap.addMapObject(&con1);
	testMap.addMapObject(&con2);
	//testMap.addMapObject(&userCharacter1);

	World Gate2158;
	Gate2158.addMap(testMap);
	Map &currentMap = Gate2158.getCurrentMap();
	Camera userCamera(window, currentMap);

    window.setVerticalSyncEnabled(true);


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
		userCamera.draw();

		sf::ConvexShape c;
		std::vector<sf::Vector2f> points = con1.getConvexPoints();
		c.setPointCount(points.size());
		int count = 0;
		for (auto & p : points){
			c.setPoint(count++, p);
		}
		c.setOrigin(con1.getOrigin());
		c.setFillColor(sf::Color::White);

		sf::ConvexShape b;
		std::vector<sf::Vector2f> pointss = con2.getConvexPoints();
		b.setPointCount(pointss.size());
		count = 0;
		for (auto & p : pointss){
			b.setPoint(count++, p);
		}
		b.setOrigin(con2.getOrigin());
		b.setFillColor(sf::Color::White);

		window.draw(b);
		window.draw(c);

		//window.draw(convex1);
		//player.draw(window);
		//menuScreen.show(true);

		//userCharacter.draw(window);
        window.display();
    }
    return 0;
}

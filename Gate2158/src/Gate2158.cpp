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


	sf::Font tFont;

	if (!tFont.loadFromFile("../../Gate2158/media/Another_America.ttf")){
		//Error handeling
	}

	sf::String ttString("Test string");
	//Always pass the font by reference, they are heavy elements! 
	//Passing nby value will give a C++ exception error
	//Loading font should be a function in the Text object, maybe load minimal amount of fonts on game startup?
	drawable *testText = new Text(ttString,  sf::Text::Style::Regular, sf::Color::Red, 30, &tFont);

	MapObject text(2, testText, sf::Vector2f{ 50.0, 0.0 });

	std::vector<sf::Vector2f> points{ 
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 200, 0 },
		sf::Vector2f{ 200, 200 },
		sf::Vector2f{ 0, 200 }
	};
	std::vector<sf::Vector2f> squarePoints{
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 50, 0 },
		sf::Vector2f{ 50, 50 },
		sf::Vector2f{ 0, 50 }
	};

	std::vector<sf::Vector2f> squarePointss{
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 40, 0 },
		sf::Vector2f{ 40, 40 },
		sf::Vector2f{ 0, 40 }
	};

	std::vector<sf::Vector2f> squarePointsss{
		sf::Vector2f{ 0, 0 },
		sf::Vector2f{ 60, 0 },
		sf::Vector2f{ 60, 60 },
		sf::Vector2f{ 0, 60 }
	};

	std::vector<sf::Vector2f> userHitbox{
		sf::Vector2f{ 20, 0 },
		sf::Vector2f{ 70, 0 },
		sf::Vector2f{ 90, 25 },
		sf::Vector2f{ 70, 50 },
		sf::Vector2f{ 20, 50 }
	};
	Convex convex(points, sf::Vector2f(300, 250), sf::Vector2f(100, 100));
	Convex convex2(squarePoints, sf::Vector2f(50, 50), sf::Vector2f(25, 25));
	Convex convex3(squarePointss, sf::Vector2f(400, 400), sf::Vector2f(20, 20));
	Convex convex4(squarePointsss, sf::Vector2f(200, 300), sf::Vector2f(30, 30));
	Convex userHit(userHitbox, sf::Vector2f(300, 100), sf::Vector2f(45,25));



	drawable *rec0 = new Rectangle(sf::Vector2f{ 200, 200 }, sf::Color::Blue);
	drawable *rec1 = new Rectangle(sf::Vector2f{ 50, 50 }, sf::Color::Red);
	drawable *rec2 = new Rectangle(sf::Vector2f{ 40, 40 }, sf::Color::Red);
	drawable *rec3 = new Rectangle(sf::Vector2f{ 60, 60 }, sf::Color::Yellow);

	MapObject con1(1, rec0, sf::Vector2f{300,250},&convex);
	MapObject con3(1, rec1, sf::Vector2f{50,50},&convex2);
	MapObject con4(1, rec2, sf::Vector2f{400,400},&convex3);
	MapObject con5(1, rec3, sf::Vector2f{200,300},&convex4);
	Sprite characterGun("../../Gate2158/media/character_gun.png");
	UserCharacter con2(100, 0, &characterGun, sf::Vector2f{300,500},&userHit);

	Map testMap(3);
	testMap.addMapObject(&con1);
	testMap.addMapObject(&con2);
	testMap.addMapObject(&con3);
	testMap.addMapObject(&con4);
	testMap.addMapObject(&con5);

//   	testMap.loadFromFile("../../Gate2158/media/maps/checkerboard.png");

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

		userInputKey.updateToggleKey();

        window.clear();

		userCamera.draw();
		menuScreen.show(true);

        window.display();
    }
    return 0;
}

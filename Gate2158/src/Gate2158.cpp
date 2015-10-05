// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Map.h"
#include "Camera.hpp"
#include "Rectangle.h"
#include "Sprite.h"
#include "Text.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Gate2158");
	Rectangle rec0(sf::Vector2f{ 50.0, 0.0 }, sf::Vector2f{ 30.0, 30.0 }, sf::Color::Blue);
	Rectangle rec1(sf::Vector2f{ 50.0, 0.0 }, sf::Vector2f{ 40.0, 40.0 }, sf::Color::Red);
	Sprite testSprite(sf::Vector2f{ 100.0, 50.0 }, "../../Gate2158/media/download.jpg");

	sf::Font tFont;

	if (!tFont.loadFromFile("../../Gate2158/media/Another_America.ttf")){
		//Error handeling
	}

	sf::String ttString("Test string");
	//Always pass the font by reference, they are heavy elements! 
	//Passing nby value will give a C++ exception error
	//Loading font should be a function in the Text object, maybe load minimal amount of fonts on game startup?
	Text testText(ttString, sf::Vector2f(50, 50), sf::Text::Style::Regular, sf::Color::White, 30, &tFont);

	MapObject picture(2, &testSprite);
	MapObject rectangle0(0, &rec0);
	MapObject rectangle1(1, &rec1);
	MapObject text(1, &testText);


	Map testMap(2);
    
	testMap.addMapObject(rectangle0);
	testMap.addMapObject(rectangle1);
	testMap.addMapObject(picture);
	testMap.addMapObject(text);

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
        }
        window.clear();
		userCamera.draw();
        window.display();
    }

    return 0;
}

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
	Text testText("Hello World!", sf::Vector2f{ 100.0, 250.0 }, sf::Text::Style::Bold, sf::Color::Red, 50);

	MapObject picture(0, &testSprite);
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

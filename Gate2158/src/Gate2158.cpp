// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Map.h"
#include "Camera.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Gate2158");
	sf::RectangleShape rec0(sf::Vector2f{ 30.0, 30.0 });
	sf::RectangleShape rec1(sf::Vector2f{ 40.0, 40.0 });
	rec1.setFillColor(sf::Color::Blue);
	MapObject rectangle0(0, rec0);
	MapObject rectangle1(1, rec1);

	Map testMap(2);
    
	testMap.addMapObject(rectangle0);
	testMap.addMapObject(rectangle1);

	World Gate2158;
	Gate2158.addMap(testMap);
	Map &currentMap = Gate2158.getCurrentMap();
	Camera userCamera(window, currentMap);

    window.setVerticalSyncEnabled(true);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


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

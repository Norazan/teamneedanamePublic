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
	MapObject rectangle0(0, rec0);
	MapObject rectangle1(1, rec0);
	std::vector<MapObject> testMap;
	testMap.push_back(rectangle0);
	testMap.push_back(rectangle1);
    
	World Gate2158;
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
        window.draw(shape);

        window.display();
    }

    return 0;
}

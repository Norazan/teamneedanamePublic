// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "World.h"
#include "Map.h"
#include "Camera.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Gate2158");
    
	World Gate2158;
	Map * currentMap;
	currentMap = Gate2158.getCurrentMap();

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

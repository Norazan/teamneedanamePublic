// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "Menu.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GATE2158");
    
    window.setVerticalSyncEnabled(true);

	Menu menuScreen;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		menuScreen.show(true, window);
        window.display();
    }

    return 0;
}

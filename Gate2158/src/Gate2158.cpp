// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "UserInput.h"
#include "UserCharacter.h"
#include <iostream>


int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	UserCharacter player = UserCharacter({ 25, 25 }, {200, 200}, sf::Color::Magenta);
	player.draw(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
		if(UserInput::getPressed('a')){
			player.move(sf::Vector2f{ -1, 0 });
		}
		if(UserInput::getPressed('d')){
			player.move(sf::Vector2f{ +1, 0 });
		}
		if(UserInput::getPressed('w')){
			player.move(sf::Vector2f{ 0, -1 });
		}
		if(UserInput::getPressed('s')){
			player.move(sf::Vector2f{ 0, +1 });
		}
        

        window.display();
    }

    return 0;
}

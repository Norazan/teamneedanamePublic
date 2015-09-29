// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "ball.h"
#include "rectangle.h"

void setWindowOptions(sf::RenderWindow & window){
	window.setVerticalSyncEnabled(true);

}


int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "Gate2158");
    window.setVerticalSyncEnabled(true);


	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	ball myBall{sf::Vector2f{200,200},50};
    rectangle myRectangle{sf::Vector2f{50,10}, sf::Color::Red};

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
        myBall.draw(window);
        myRectangle.draw(window, sf::Vector2f{50,50});
		window.display();
	}

	return 0;
}

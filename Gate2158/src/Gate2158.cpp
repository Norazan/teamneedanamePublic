// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include "TitleScreen.h"
#include "UserInput.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "GATE2158");
    
    window.setVerticalSyncEnabled(true);

	Menu menuScreen(window);
	UserInput userInputKey;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
		if (userInputKey.getPressed('w')){
			if (menuScreen.getCurrentSelection() == 1){
				menuScreen.setCurrentSelection(2);
			}
			else{
				menuScreen.setCurrentSelection(1);
			}
		}
		else if (userInputKey.getPressed('s')){
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

        window.clear();
		menuScreen.show(true);
        window.display();
    }

    return 0;
}

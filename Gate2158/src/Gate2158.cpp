// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UserInput.h"
#include "Menu.h"
#include "World.h"
#include "Map.h"
#include "Camera.hpp"
#include <iostream>

int main()
{
	int width= 1280;
	int height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "Gate2158");

	Camera *userCamera = Camera::getInstance();
	UserInput userInputKey;
	Menu menuScreen(window, true);


	Sprite backgroundSprite("../../Gate2158/media/textures/background.jpeg");

 	Map testMap(20);
	testMap.loadFromFile("../../Gate2158/media/maps/mainmap.png");

	World Gate2158;
	Gate2158.addMap(testMap);
	Map &currentMap = Gate2158.getCurrentMap();
	
	userCamera->setCurrentMap(currentMap);
	userCamera->setWindow(window);
	userCamera->setCurrentPlayer(currentMap.getCurrentPlayer());
	
    window.setVerticalSyncEnabled(true);

	sf::Music gameMusic;
	if (!gameMusic.openFromFile("../../Gate2158/media/audio/bensound-scifi.wav")){
		return -1;
	}
	gameMusic.setLoop(true);
	


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
		if (menuScreen.getShowingMenu()){
			menuScreen.draw();
		}
		else{
			if (gameMusic.getStatus() != sf::SoundSource::Status::Playing){
				gameMusic.play();
			}
			backgroundSprite.draw(window, sf::Vector2f{ 640, 360 });
			userCamera->draw();
		}

        window.display();
    }
    return 0;
}

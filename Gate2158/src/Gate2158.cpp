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

	// load font
	sf::Font tFont;
	tFont.loadFromFile("../../Gate2158/media/fonts/Inversionz.otf");

	Sprite backgroundSprite("../../Gate2158/media/textures/Background_new.png");

 	Map testMap(20);
 	testMap.loadFromFile("../../Gate2158/media/maps/mainmap.png");

	Map level2(5);
	level2.loadFromFile("../../Gate2158/media/maps/lvl2.png");

	World Gate2158;
	Gate2158.addMap(testMap);
	Gate2158.addMap(level2);
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
		if (userCamera->endGame){
			Text gameover(
				"GAME OVER",
				sf::Vector2f(0, 0),
				sf::Text::Regular,
				sf::Color::Red,
				90,
				&tFont
			);
			gameover.draw(window, sf::Vector2f(400, 360));
			sf::sleep(sf::seconds(5));
			exit(0);
		}
		if (userCamera->nextLevel){
			Text nextLevel(
				"next level",
				sf::Vector2f(0, 0),
				sf::Text::Regular,
				sf::Color::Red,
				90,
				&tFont
				);
			nextLevel.draw(window, sf::Vector2f(400, 360));
			sf::sleep(sf::seconds(2));
			Gate2158.nextMap();
			std::vector<int> tiers = currentMap.player->getWeaponTiers();
			currentMap = Gate2158.getCurrentMap();
			currentMap.player->setWeaponTiers(tiers);
			userCamera->setCurrentMap(Gate2158.getCurrentMap());
			userCamera->setCurrentPlayer(currentMap.getCurrentPlayer());
		}
        window.display();
    }
    return 0;
}

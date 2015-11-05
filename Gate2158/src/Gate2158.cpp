// Gate2158.cpp : Defines the entry point for the console application.
//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "UserInput.h"
#include "Menu.h"
#include "World.h"
#include "Map.h"
#include "Camera.hpp"
#include "Rectangle.h"
#include "Sprite.h"
#include "Text.h"
#include "Circle.h"
#include "Character.h"
#include "UserCharacter.h"
#include "Convex.h"
#include "Enemy.h"
#include <iostream>

int main()
{

	/*sf::Music backgroundMusic;
	
	if (!backgroundMusic.openFromFile("../../Gate2158/media/audio/Analog_Boys_2.wav")){
		return -1;
	}
	backgroundMusic.setLoop(true);

	backgroundMusic.play();*/

	int width= 1280;
	int height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "Gate2158");

	Camera *userCamera = Camera::getInstance();
	UserInput userInputKey;
	Menu menuScreen(window, true);


	//sf::Font tFont;

	//if (!tFont.loadFromFile("../../Gate2158/media/Another_America.ttf")){
		//Error handeling
	//}

	//sf::String ttString("Test string");
	//Always pass the font by reference, they are heavy elements! 
	//Passing nby value will give a C++ exception error
	//Loading font should be a function in the Text object, maybe load minimal amount of fonts on game startup?
	//drawable *testText = new Text(ttString,  sf::Text::Style::Regular, sf::Color::Red, 30, &tFont);

	//MapObject text(2, testText, sf::Vector2f{ 50.0, 0.0 });

	//Text testText(ttString, sf::Vector2f(200, 200), sf::Text::Style::Regular, sf::Color::Red, 30, &tFont);

	/*drawable *rec0 = new Rectangle(sf::Vector2f{ 200, 300 }, sf::Color::Blue);
	drawable *rec1 = new Rectangle(sf::Vector2f{ 50, 50 }, sf::Color::Red);
	drawable *rec2 = new Rectangle(sf::Vector2f{ 40, 40 }, sf::Color::Red);
	drawable *rec3 = new Rectangle(sf::Vector2f{ 60, 60 }, sf::Color::Yellow);

	MapObject con1(1, rec0, sf::Vector2f{300,250});
	MapObject con3(1, rec1, sf::Vector2f{50,50},&convex2);
	MapObject con5(1, rec3, sf::Vector2f{ 200, 300 }, &convex4);*/
	
	/*UserCharacter con2(1000, 0, &characterGun, sf::Vector2f{ 300, 500 }, &userHit);
	Enemy enemy2(sf::Vector2f{ 700, 500 }, &con2, "pistol", 200, 1, &enemyHit2, &enemy);
	Enemy enemy3(sf::Vector2f{ 300, 600 }, &con2, "pistol", 300, 1, &enemyHit3, &enemy);
	Enemy enemy4(sf::Vector2f{ 600, 500 }, &con2, "shotgun", 400, 1, &enemyHit4, &enemy);*/

 	Map testMap(3);
	testMap.loadFromFile("../../Gate2158/media/maps/mainmap.png");
	/*testMap.addMapObject(&con1);
	testMap.addMapObject(&con2);
	testMap.addMapObject(&con3);
	testMap.addMapObject(&con5);
	testMap.addMapObject(&enemy2);
	testMap.addMapObject(&enemy3);*/
	//testMap.addMapObject(&enemy4);

//   	testMap.loadFromFile("../../Gate2158/media/maps/checkerboard.png");

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
			userCamera->draw();
		}
        window.display();
    }
    return 0;
}

#include "Menu.h"

Menu::Menu(sf::RenderWindow &windowRef)
: window(windowRef),
 showingMenu(false),
 currentSelection(1),
 splashScreen(true)
{

}

void Menu::show(bool showMenu){
	if (splashScreen){
		sf::Texture logoTexture;
		if (!logoTexture.loadFromFile("../../Gate2158/media/TEAMNEEDSANAME.png")){
		}
		sf::Sprite logo;
		logo.setTexture(logoTexture);
		logo.setPosition(sf::Vector2f(1280 / 2 - 500 / 2, 720 / 2 - 380 / 2));
		window.draw(logo);
	}
	else{
		sf::Texture logoTexture;
		if (!logoTexture.loadFromFile("../../Gate2158/media/TEAMNEEDSANAME.png")){
		}
		sf::Sprite logo;
		logo.setTexture(logoTexture);
		logo.setPosition(sf::Vector2f(1280 / 2 - 500 / 2, 0));

		sf::RectangleShape choiceOne(sf::Vector2f(200, 100));
		choiceOne.setPosition(1280 / 2 - 200 / 2, 400);
		choiceOne.setFillColor(sf::Color::Blue);
		sf::RectangleShape choiceTwo(sf::Vector2f(200, 100));
		choiceTwo.setPosition(1280 / 2 - 200 / 2, 550);
		choiceTwo.setFillColor(sf::Color::Magenta);
		sf::CircleShape select1(20);
		sf::CircleShape select2(20);
		select1.setFillColor(sf::Color::White);
		select2.setFillColor(sf::Color::White);
		if (currentSelection == 1){
			select1.setPosition(1280 / 2 - 200, 425);
			select2.setPosition(1280 / 2 + 150, 425);
		}
		if (currentSelection == 2){
			select1.setPosition(1280 / 2 - 200, 575);
			select2.setPosition(1280 / 2 + 150, 575);
		}

		window.draw(logo);
		window.draw(choiceOne);
		window.draw(choiceTwo);
		window.draw(select1);
		window.draw(select2);
	}
}
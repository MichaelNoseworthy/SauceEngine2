#pragma once
#include <iostream>
#include "SceneManager.h"

#include <SFML/Graphics.hpp>

class scene_0 : public SceneManager
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	scene_0(void);
	virtual int Run(sf::RenderWindow &App);
};

scene_0::scene_0(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int scene_0::Run(sf::RenderWindow &App)
{

	sf::Clock clock;

	sf::Texture SplashScreenImage;
	if (!SplashScreenImage.loadFromFile("../../Assets/images/SplashScreen.jpg") || !SplashScreenImage.loadFromFile("../../Assets/images/SplashScreen.jpg"))
	{
		//find it in the game directory instead
		if (!SplashScreenImage.loadFromFile("./Assets/images/SplashScreen.jpg") || !SplashScreenImage.loadFromFile("./Assets/images/SplashScreen.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	sf::Sprite SplashSprite(SplashScreenImage);
	SplashSprite.setOrigin(sf::Vector2f(SplashScreenImage.getSize()) / 2.f);
	SplashSprite.setPosition(SplashSprite.getOrigin());


	while (true)
	{
		sf::Time elapsed1 = clock.getElapsedTime();
		if (elapsed1 >= sf::seconds(3.0f))
		{
			return (1); // Go to scene_1
		}
		else
		{

			App.clear(sf::Color::Blue);
			App.draw(SplashSprite);
			App.display();
		}
	}

	//Clearing screen
	App.clear();
	//Drawing
	//App.draw(Sprite);

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
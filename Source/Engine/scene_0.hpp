#pragma once
#include <iostream>
#include "SceneManager.h"
#include "AssetLoader.h"

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

	loadAssetFromFile(SplashScreenImage, "../../Assets/images/SplashScreen.jpg", "./Assets/images/SplashScreen.jpg");

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

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
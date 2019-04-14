/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#pragma once
#include <iostream>
#include "SceneManager.h"
#include "AssetLoader.h"
//#include "AssetManager.h"

#include <SFML/Graphics.hpp>

//extern AssetManager Assets;
extern int lastscene;


class scene_1 : public SceneManager
{
private:
	int alpha_max;
	int alpha_div;
	bool playing;
public:
	scene_1(void);
	virtual int Run(sf::RenderWindow &App);
};

scene_1::scene_1(void)
{
	alpha_max = 3 * 255;
	alpha_div = 3;
	playing = false;
}

int scene_1::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Texture Texture;
	sf::Sprite Sprite;
	int alpha = 0;
	sf::Font Font;
	sf::Text Menu1;
	sf::Text Menu2;
	sf::Text Menu3;
	int menu = 0;
	

	//loadAssetFromFile(Texture, "../../Assets/images/present.png", "./Assets/images/present.png");

	/*
	sf::Sprite Sprite2;
	//sf::Texture Texture2;
	//Sprite2.setColor(sf::Color(255, 255, 255, alpha));
	Sprite2.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
	Sprite2.setPosition({ 380.f, 220.f });
	*/


	

	AssetManager::loadTexture("present", "../../Assets/images/chanchoCero.png", "./Assets/images/chanchoCero.png");
	Sprite.setTexture(*AssetManager::getTexture("present"));
	Sprite.setPosition(sf::Vector2f(0, 0));
	Sprite.setScale(sf::Vector2f(2.3, 2.7));
	//Sprite.setTexture(Texture);
	Sprite.setColor(sf::Color(255, 255, 255, alpha));

	

	//loadAssetFromFile(Font, "../../Assets/fonts/verdanab.ttf", "./Assets/fonts/verdanab.ttf");
	AssetManager::loadFont("verdanab", "../../Assets/fonts/verdanab.ttf", "./Assets/fonts/verdanab.ttf");
	Menu1.setFont(*AssetManager::getFont("verdanab"));
	Menu1.setCharacterSize(20);
	Menu1.setString("Play");
	Menu1.setPosition({ 280.f, 160.f });

	Menu2.setFont(*AssetManager::getFont("verdanab"));
	Menu2.setCharacterSize(20);
	Menu2.setString("Exit");
	Menu2.setPosition({ 280.f, 220.f });

	Menu3.setFont(*AssetManager::getFont("verdanab"));
	Menu3.setCharacterSize(20);
	Menu3.setString("Continue");
	Menu3.setPosition({ 280.f, 160.f });

	sf::Sound dingSound;
	sf::SoundBuffer buffer2;
	loadAssetFromFile(buffer2, "../../Assets/Sounds/ding_on.wav", "../../Assets/Sounds/ding_on.wav");
	dingSound.setBuffer(buffer2);

	//ding_on.wav

	

	if (playing)
	{
		alpha = alpha_max;
	}

	while (Running)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Up:
					menu = 0;
					dingSound.play();
					break;
				case sf::Keyboard::Down:
					menu = 1;
					dingSound.play();
					break;
				case sf::Keyboard::Return:
					if (menu == 0)
					{
						//Let's get play !
						playing = true;
						return (lastscene);
					}
					else
					{
						//Let's get work...
						return (-1);
					}
					break;
				default:
					break;
				}
			}
		}
		//When getting at alpha_max, we stop modifying the sprite
		if (alpha < alpha_max)
		{
			alpha++;
		}
		Sprite.setColor(sf::Color(255, 255, 255, alpha / alpha_div));
		if (menu == 0)
		{
			Menu1.setColor(sf::Color(255, 0, 0, 255));
			Menu2.setColor(sf::Color(255, 255, 255, 255));
			Menu3.setColor(sf::Color(255, 0, 0, 255));
		}
		else
		{
			Menu1.setColor(sf::Color(255, 255, 255, 255));
			Menu2.setColor(sf::Color(255, 0, 0, 255));
			Menu3.setColor(sf::Color(255, 255, 255, 255));
		}

		//Clearing screen
		App.clear();
		//Drawing
		//App.draw(Sprite);
		App.draw(Sprite);
		if (alpha == alpha_max)
		{
			if (playing)
			{
				App.draw(Menu3);
			}
			else
			{
				App.draw(Menu1);
			}
			App.draw(Menu2);
		}
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}
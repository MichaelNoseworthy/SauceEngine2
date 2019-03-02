#pragma once
#include <iostream>
#include "SceneManager.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
class scene_2 : public SceneManager
{
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	scene_2(void);
	virtual int Run(sf::RenderWindow &App);
};


scene_2::scene_2(void)
{
	movement_step = 5;
	posx = 320;
	posy = 240;
	//Setting sprite
	Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	Rectangle.setSize({ 10.f, 10.f });
}

int scene_2::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Music music;
	bool isPlaying = true;
	if (!music.openFromFile("../../Assets/Music/metroid03.ogg"))
		return -1; // error
	music.play();
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
				case sf::Keyboard::Escape:
					return (1); 
					break;
				case sf::Keyboard::Up:
					posy -= movement_step;
					break;
				case sf::Keyboard::Down:
					posy += movement_step;
					break;
				case sf::Keyboard::Left:
					posx -= movement_step;
					break;
				case sf::Keyboard::Right:
					posx += movement_step;
					break;
				default:
					break;
				}
				if (Event.type == sf::Event::KeyPressed)
					if (Event.key.code == sf::Keyboard::P)
					{
						if (isPlaying)
						{
							music.stop();
							isPlaying = false;
						}
						else
						{
							music.play();
							isPlaying = true;
						}
						
					}
			}
		}

		//Updating
		if (posx > 630)
			posx = 630;
		if (posx < 0)
			posx = 0;
		if (posy > 470)
			posy = 470;
		if (posy < 0)
			posy = 0;
		Rectangle.setPosition({ posx, posy });

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		App.draw(Rectangle);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}
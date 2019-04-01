/*##############################################################################
#                                                                              #
# Copyright 2018 Sauce Pig All Rights Reserved.                                #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include <iostream>
#include "SceneManager.h"
#include "Components/GameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <limits>
#include "Collision.h"
#include "Player.h"
#include "Platform.h"

extern int lastscene;

class scene_3 : public SceneManager
{
private:
	float movement_step;
	float posx;
	float posy;
	float deltaTime;	
	GameObject background;
	
	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
	sf::Clock clock;
	sf::View view;
	sf::View defaultView;
public:
	scene_3(void);
	virtual int Run(sf::RenderWindow &App);		
};

scene_3::scene_3(void)	
{	
	deltaTime = 0;
}

int scene_3::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Music music;
	bool isPlaying = true;
	lastscene = 3;
	loadAssetFromFile(music, "../../Assets/Music/metroid03.ogg", "./Assets/Music/metroid03.ogg");
	//music.play();
	//texture then size then position
	Platform platform1(nullptr, sf::Vector2f(160.0f, 20.0f), sf::Vector2f(150.0f, 300.0f));
	Platform platform2(nullptr, sf::Vector2f(160.0f, 20.0f), sf::Vector2f(450.0f, 300.0f));
	

	background.SetPosition(sf::Vector2f(0, 0));
	
	if (!backgroundTexture.loadFromFile("../../Assets/images/scene2/background800x600.jpg"))
	{
		//find it in the game directory instead
		if (!backgroundTexture.loadFromFile("./Assets/images/scene2/background800x600.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	background.sprite.setTexture(backgroundTexture);
	
	if (!playerTexture.loadFromFile("../../Assets/images/scene2/player.jpg"))
	{
		//find it in the game directory instead
		if (!backgroundTexture.loadFromFile("./Assets/images/scene2/player.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}
		
	Player player(&playerTexture, sf::Vector2u(1, 1), 0.3, 100, 200); //texture, animation stuff, timer for animation, power to push in case needed and jumpforce
	
	//animation
	Animation animation(&playerTexture, sf::Vector2u(3, 1), 0.3f);
	player.SetPosition(sf::Vector2f(0, 0));

	while (Running)
	{	
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f) {
			deltaTime = 1.0f / 20.0f;
		}
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
					defaultView = App.getDefaultView();
					App.setView(defaultView);
					return (1);
					break;
				case sf::Keyboard::Up:
					//
					
					
					break;
				case sf::Keyboard::Down:
					
					break;
				case sf::Keyboard::Left:
					
					break;
				case sf::Keyboard::Right:
					
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

		animation.Update(0, deltaTime);
		//settexutre? settexturerect?
		player.Update(deltaTime);
		
		view.setCenter(player.GetPosition());

		sf::Vector2f direction;

		if (platform1.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}
		if (platform2.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		App.setView(view);
		view.setViewport(sf::FloatRect(-0.5f, -0.5f, 2.0f, 2.0f));
		//Drawing
		App.draw(background.sprite);
		platform1.Draw(App);
		platform2.Draw(App);
		player.Draw(App);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}

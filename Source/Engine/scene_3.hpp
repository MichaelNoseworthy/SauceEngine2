#include <iostream>
#include "SceneManager.h"
#include "Components/GameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <limits>
#include "Collision.h"
#include "Player.h"

class scene_3 : public SceneManager
{
private:
	float movement_step;
	float posx;
	float posy;
	Player player;
	GameObject background;
	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
public:
	scene_3(void);
	virtual int Run(sf::RenderWindow &App);	
};

scene_3::scene_3(void)	
{
	//Player(&playerTexture, sf::Vector2u(0, 0), 0.3, 100);
}

int scene_3::Run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool Running = true;
	sf::Music music;
	bool isPlaying = true;
	loadAssetFromFile(music, "../../Assets/Music/metroid03.ogg", "./Assets/Music/metroid03.ogg");
	//music.play();

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

	player = Player(&playerTexture, sf::Vector2u(10, 10), 0.3, 100);

	player.SetPosition(sf::Vector2f(0, 0));
	


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

	
		//Updating
	/*	if (posx > 630)
			posx = 630;
		if (posx < 0)
			posx = 0;
		if (posy > 470)
			posy = 470;
		if (posy < 0)
			posy = 0;*/
		//Rectangle.setPosition({ posx, posy });

		/*square.sprite.setPosition({ posx, posy });*/

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		App.draw(background.sprite);
		player.Draw(App);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}

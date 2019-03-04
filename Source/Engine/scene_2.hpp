#pragma once
#include <iostream>
#include "SceneManager.h"
#include "Components/GameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <limits>
#include "Collision.h"


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
	GameObject background;
	sf::Texture backgroundTexture;
	GameObject platform;
	sf::Texture platformTexture;
	GameObject platform2;
	sf::Texture platformTexture2;
	GameObject platform3;
	sf::Texture platformTexture3;
	GameObject moon;
	sf::Texture moonTexture;
	GameObject beam1;
	GameObject beam2;
	GameObject beam3;
	sf::Texture beam1Texture;
	sf::Texture beam2Texture;
	GameObject pelton;
	sf::Texture peltonTexture;
	GameObject blocks1;
	GameObject blocks2;
	GameObject blocks3;
	sf::Texture blocksTexture;

	GameObject sphere1;
	GameObject sphere2;
	sf::Texture sphereTexture;

	GameObject square;
	sf::Texture squareTexture;
	

	GameObject root1;
	GameObject root2;
	sf::Texture rootTexture;

	bool canGoDown = true;
	bool canGoUp = true;
	bool canGoRight = true;
	bool canGoLeft = true;

	int lastPressed = 0;
	
};


scene_2::scene_2(void)
{
	movement_step = 1;
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
	loadAssetFromFile(music, "../../Assets/Music/metroid03.ogg", "./Assets/Music/metroid03.ogg");
	music.play();

	background.SetPosition(sf::Vector2f(0, 0));

	platform.SetPosition(sf::Vector2f(330, 438));
	platform2.SetPosition(sf::Vector2f(550, 438));
	platform3.SetPosition(sf::Vector2f(150, 438));
	moon.SetPosition(sf::Vector2f(500, 100));
	beam1.SetPosition(sf::Vector2f(450, 305));
	beam2.SetPosition(sf::Vector2f(250, 305));
	beam3.SetPosition(sf::Vector2f(350, 200));
	blocks1.SetPosition(sf::Vector2f(226, 410));
	blocks2.SetPosition(sf::Vector2f(266, 410));
	blocks3.SetPosition(sf::Vector2f(246, 410));
	pelton.SetPosition(sf::Vector2f(325, 384));
	sphere1.SetPosition(sf::Vector2f(425, 410));
	sphere2.SetPosition(sf::Vector2f(405, 410));
	root1.SetPosition(sf::Vector2f(445, 410));
	root2.SetPosition(sf::Vector2f(465, 410));
	square.SetPosition(sf::Vector2f(320, 245));

	/*
	if (!squareTexture.loadFromFile("../../Assets/images/scene1/square.jpg"))
	{
		//find it in the game directory instead
		if (!squareTexture.loadFromFile("./Assets/images/scene1/square.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}*/

	loadAssetFromFile(squareTexture, "../../Assets/images/scene1/square.jpg", "./Assets/images/scene1/square.jpg");

	//Collision::CreateTextureAndBitmask(squareTexture, "../../Assets/images/scene1/square.jpg");

	square.sprite.setTexture(squareTexture);
	//square.sprite.setOrigin(sf::Vector2f(square.sprite.getTexture()->getSize().x*0.5f, square.sprite.getTexture()->getSize().y*0.5f));		

	if (!backgroundTexture.loadFromFile("../../Assets/images/scene1/background800x600.jpg"))
	{
		//find it in the game directory instead
		if (!backgroundTexture.loadFromFile("./Assets/images/scene1/background800x600.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	background.sprite.setTexture(backgroundTexture);
	//Rectangle.setOrigin(sf::Vector2f(Rectangle.getTexture()->getSize().x*0.5f, Rectangle.getTexture()->getSize().y*0.5f));

	if (!sphereTexture.loadFromFile("../../Assets/images/scene1/sphere.jpg"))
	{
		//find it in the game directory instead
		if (!sphereTexture.loadFromFile("./Assets/images/scene1/sphere.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	sphere1.sprite.setTexture(sphereTexture);
	sphere1.sprite.setOrigin(sf::Vector2f(sphere1.sprite.getTexture()->getSize().x*0.5f, sphere1.sprite.getTexture()->getSize().y*0.5f));
	sphere2.sprite.setTexture(sphereTexture);
	sphere2.sprite.setOrigin(sf::Vector2f(sphere2.sprite.getTexture()->getSize().x*0.5f, sphere2.sprite.getTexture()->getSize().y*0.5f));


	if (!rootTexture.loadFromFile("../../Assets/images/scene1/wires.jpg"))
	{
		//find it in the game directory instead
		if (!rootTexture.loadFromFile("./Assets/images/scene1/wires.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	root1.sprite.setTexture(rootTexture);
	root1.sprite.setOrigin(sf::Vector2f(root1.sprite.getTexture()->getSize().x*0.5f, root1.sprite.getTexture()->getSize().y*0.5f));
	root2.sprite.setTexture(rootTexture);
	root2.sprite.setOrigin(sf::Vector2f(root2.sprite.getTexture()->getSize().x*0.5f, root2.sprite.getTexture()->getSize().y*0.5f));

	if (!platformTexture.loadFromFile("../../Assets/images/scene1/ground.jpg"))
	{
		//find it in the game directory instead
		if (!platformTexture.loadFromFile("./Assets/images/scene1/ground.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	platform.sprite.setTexture(platformTexture);
	platform.sprite.setOrigin(sf::Vector2f(platform.sprite.getTexture()->getSize().x*0.5f, platform.sprite.getTexture()->getSize().y*0.5f));
	platform2.sprite.setTexture(platformTexture);
	platform2.sprite.setOrigin(sf::Vector2f(platform.sprite.getTexture()->getSize().x*0.5f, platform.sprite.getTexture()->getSize().y*0.5f));
	platform3.sprite.setTexture(platformTexture);
	platform3.sprite.setOrigin(sf::Vector2f(platform.sprite.getTexture()->getSize().x*0.5f, platform.sprite.getTexture()->getSize().y*0.5f));

	if (!peltonTexture.loadFromFile("../../Assets/images/scene1/pelton.jpg"))
	{
		//find it in the game directory instead
		if (!peltonTexture.loadFromFile("./Assets/images/scene1/pelton.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	pelton.sprite.setTexture(peltonTexture);

	if (!blocksTexture.loadFromFile("../../Assets/images/scene1/block.jpg"))
	{
		//find it in the game directory instead
		if (!blocksTexture.loadFromFile("./Assets/images/scene1/block.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	blocks1.sprite.setTexture(blocksTexture);
	blocks1.sprite.setOrigin(sf::Vector2f(blocks1.sprite.getTexture()->getSize().x*0.5f, blocks1.sprite.getTexture()->getSize().y*0.5f));
	blocks2.sprite.setTexture(blocksTexture);
	blocks2.sprite.setOrigin(sf::Vector2f(blocks2.sprite.getTexture()->getSize().x*0.5f, blocks2.sprite.getTexture()->getSize().y*0.5f));
	blocks3.sprite.setTexture(blocksTexture);
	blocks3.sprite.setOrigin(sf::Vector2f(blocks3.sprite.getTexture()->getSize().x*0.5f, blocks3.sprite.getTexture()->getSize().y*0.5f));

	/*
	if (!beam1Texture.loadFromFile("../../Assets/images/scene1/platformBlue.png"))
	{
		//find it in the game directory instead
		if (!beam1Texture.loadFromFile("./Assets/images/scene1/platformBlue.png"))
			return EXIT_FAILURE; //can't find it at all
	}*/

	Collision::CreateTextureAndBitmask(beam1Texture, "../../Assets/images/scene1/platformBlue.png");

	beam1.sprite.setTexture(beam1Texture);
	beam1.sprite.setOrigin(sf::Vector2f(beam1.sprite.getTexture()->getSize().x*0.5f, beam1.sprite.getTexture()->getSize().y*0.5f));
	beam2.sprite.setTexture(beam1Texture);
	beam2.sprite.setOrigin(sf::Vector2f(beam2.sprite.getTexture()->getSize().x*0.5f, beam2.sprite.getTexture()->getSize().y*0.5f));

	if (!beam2Texture.loadFromFile("../../Assets/images/scene1/platformBlueUp.png"))
	{
		//find it in the game directory instead
		if (!beam2Texture.loadFromFile("./Assets/images/scene1/platformBlueUp.png"))
			return EXIT_FAILURE; //can't find it at all
	}

	beam3.sprite.setTexture(beam2Texture);
	beam3.sprite.setOrigin(sf::Vector2f(beam3.sprite.getTexture()->getSize().x*0.5f, beam3.sprite.getTexture()->getSize().y*0.5f));

	if (!moonTexture.loadFromFile("../../Assets/images/scene1/moon.jpg"))
	{
		//find it in the game directory instead
		if (!moonTexture.loadFromFile("./Assets/images/scene1/moon.jpg"))
			return EXIT_FAILURE; //can't find it at all
	}

	moon.sprite.setTexture(moonTexture);
	moon.sprite.setOrigin(sf::Vector2f(moon.sprite.getTexture()->getSize().x*0.5f, moon.sprite.getTexture()->getSize().y*0.5f));

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
					lastPressed = 0;
					if (canGoUp) {
						posy -= movement_step;
						canGoDown = true;
						canGoRight = true;
						canGoLeft = true;
					}
					break;
				case sf::Keyboard::Down:
					lastPressed = 2;
					if (canGoDown) {
						posy += movement_step;
						canGoUp = true;
						canGoRight = true;
						canGoLeft = true;
					}
					break;
				case sf::Keyboard::Left:
					lastPressed = 3;
					if (canGoLeft) {
						posx -= movement_step;
						canGoRight = true;
						canGoUp = true;
						canGoDown = true;
					}					
					break;
				case sf::Keyboard::Right:
					lastPressed = 1;
					if (canGoRight) {
						posx += movement_step;
						canGoLeft = true;						
						canGoUp = true;
						canGoDown = true;
					}					
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

		if (Collision::BoundingBoxTest(square.sprite, platform.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, platform2.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, blocks1.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, blocks2.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, root1.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, root2.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, sphere1.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, sphere2.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, blocks3.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, platform3.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, beam1.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, beam1.sprite) && lastPressed == 0) {
			canGoUp = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, sphere1.sprite) && lastPressed == 0) {
			canGoUp = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, sphere1.sprite) && lastPressed == 0) {
			canGoUp = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, root1.sprite) && lastPressed == 0) {
			canGoUp = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, root2.sprite) && lastPressed == 0) {
			canGoUp = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, beam1.sprite) && lastPressed == 1) {
			canGoRight = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, platform2.sprite) && lastPressed == 1) {
			canGoRight = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, platform3.sprite) && lastPressed == 1) {
			canGoRight = false;
		}

		if (Collision::PixelPerfectTest(square.sprite, beam1.sprite) && lastPressed == 3) {
			canGoLeft = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, platform2.sprite) && lastPressed == 3) {
			canGoLeft = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, platform.sprite) && lastPressed == 3) {
			canGoLeft = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, platform3.sprite) && lastPressed == 3) {
			canGoLeft = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, beam2.sprite) && lastPressed == 2) {
			canGoDown = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, beam2.sprite) && lastPressed == 0) {
			canGoUp = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, beam2.sprite) && lastPressed == 1) {
			canGoRight = false;
		}

		if (Collision::BoundingBoxTest(square.sprite, beam2.sprite) && lastPressed == 3) {
			canGoLeft = false;
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
		//Rectangle.setPosition({ posx, posy });

		square.sprite.setPosition({ posx, posy });

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		App.draw(background.sprite);
		App.draw(platform.sprite);
		App.draw(platform2.sprite);
		App.draw(platform3.sprite);
		//App.draw(Rectangle);
		App.draw(moon.sprite);
	//	App.draw(beam1.sprite);
	//	App.draw(beam2.sprite);
		App.draw(pelton.sprite);
	//	App.draw(beam3.sprite);
		App.draw(blocks1.sprite);
		App.draw(blocks2.sprite);
		App.draw(blocks3.sprite);
		App.draw(sphere2.sprite);
		App.draw(sphere1.sprite);
		App.draw(root2.sprite);
		App.draw(root1.sprite);
		App.draw(square.sprite);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}
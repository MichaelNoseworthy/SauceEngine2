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
#include <vector>
#include "Collision.h"
#include "Player.h"
#include "Platform.h"
#include "Projectile.h"

extern int lastscene;

class scene_3 : public SceneManager
{
private:
	float movement_step;
	float posx;
	float posy;
	float deltaTime;
	GameObject background;
	GameObject background2;
	GameObject background3;
	GameObject background4;

	sf::Texture backgroundTexture;
	sf::Texture playerTexture;
	sf::Texture projectileTexture;
	sf::Clock clock;
	sf::View view;
	sf::View defaultView;
	std::vector<Projectile> projectileHolder;

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
	Platform platform3(nullptr, sf::Vector2f(40.0f, 20.0f), sf::Vector2f(270.0f, 350.0f));
	Platform platform4(nullptr, sf::Vector2f(600.0f, 20.0f), sf::Vector2f(200.0f, 400.0f));
	Platform platform5(nullptr, sf::Vector2f(40.0f, 20.0f), sf::Vector2f(0.0f, 350.0f));

	background.SetPosition(sf::Vector2f(-800, 0));
	background2.SetPosition(sf::Vector2f(0, 0));
	background3.SetPosition(sf::Vector2f(0, -600));
	background4.SetPosition(sf::Vector2f(0, 600));
	loadAssetFromFile(projectileTexture, "../../Assets/images/scene2/shoot.png", "./Assets/images/scene2/shoot.png");
	loadAssetFromFile(backgroundTexture, "../../Assets/images/scene2/background800x600.jpg", "./Assets/images/scene2/background800x600.jpg");

	backgroundTexture.setRepeated(true);
	background.sprite.setTexture(backgroundTexture);
	background2.sprite.setTexture(backgroundTexture);
	background4.sprite.setTexture(backgroundTexture);
	background3.sprite.setTexture(backgroundTexture);


	loadAssetFromFile(playerTexture, "../../Assets/images/scene3/RamusAll.png", "./Assets/images/scene2/RamusAll.png");
	/*
	//test code beings
	//---BACKGROUND CREATION---//
	std::vector<std::vector<sf::RenderTexture*>> background;
	std::vector<sf::Sprite*> sprites;
	int MAP_TILE_WIDTH = 800*100;
	int MAP_TILE_HEIGHT = 600*1;
	int TILE_WIDTH = 800;
	int TILE_HEIGHT = 600;
	for (int x = 0; x < MAP_TILE_WIDTH; ++x)
	{
		for (int y = 0; y < MAP_TILE_HEIGHT; ++y)
		{
			background[x][y] = new sf::RenderTexture::create(TILE_WIDTH, TILE_HEIGHT);
			background[x][y]->create(TILE_WIDTH, TILE_HEIGHT);
			background[x][y]->setView(sf::FloatRect(x * TILE_WIDTH,
				y * TILE_HEIGHT,
				TILE_WIDTH,
				TILE_HEIGHT));
		}
	}
	for (sf::Sprite *sprite : sprites)
	{
		const sf::Vector2f &position = sprite->getPosition();
		background[position.x / TILE_WIDTH][position.y / TILE_HEIGHT]->draw(*sprite);
	}
	//---BACKGROUND RENDERING---//
	const sf::Vector2f topLeft = App.display->mapPixelToCoords(sf::Vector2f(0, 0));
	const sf::Vector2f bottomRight = App.display->mapPixelToCoords(App.display->getView().getSize());
	for (int x = topLeft.x / TILE_WIDTH; x <= bottomRight.x / TILE_WIDTH; ++x)
	{
		for (int y = topLeft.y / TILE_HEIGHT; y <= bottomRight.y / TILE_HEIGHT; ++y)
		{
			App.display->draw(background[x][y]->getTexture());
		}
	}
	//test code ends
	*/


	Player player(&playerTexture, sf::Vector2u(3, 5), 0.3, 70, 50); //texture, animation stuff, timer for animation,
																	//power to push in case needed and jumpforce
																	//3x5 = sprite animator

	//animation
	//Animation animation(&playerTexture, sf::Vector2u(3, 1), 0.3f);
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
					else if (Event.key.code == sf::Keyboard::L) {
						Projectile newProjectile(&projectileTexture, sf::Vector2u(1, 1), 0.3, 20); //player speed 50 as reference
						newProjectile.SetPos(sf::Vector2f(player.GetPositionX() + 15.0f, player.GetPositionY()));
						projectileHolder.push_back(newProjectile);
					}
			}

		}

		for (int i = 0; i < projectileHolder.size(); i++) {
			projectileHolder[i].Draw(App);
			projectileHolder[i].Update(deltaTime);
		}

		player.Update(deltaTime);

		view.setCenter(player.GetPosition());

		sf::Vector2f direction;

		if (platform1.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}
		if (platform2.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}
		if (platform3.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}
		if (platform4.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}
		if (platform5.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f)) {
			player.OnCollision(direction);
		}

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		App.setView(view);
		view.setViewport(sf::FloatRect(-0.5f, -0.5f, 2.0f, 2.0f));
		//Drawing
		App.draw(background.sprite);
		App.draw(background2.sprite);
		App.draw(background3.sprite);
		App.draw(background4.sprite);
		platform1.Draw(App);
		platform3.Draw(App);
		platform2.Draw(App);
		platform4.Draw(App);
		platform5.Draw(App);
		player.Draw(App);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}

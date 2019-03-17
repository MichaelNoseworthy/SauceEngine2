#include "Player.h"


//Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
Player::Player(sf::Texture* Texture, sf::Vector2u imageCount, float switchTime, float speed)
{
	switchTime = 0.5;
	this->speed = speed;
	//this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(Texture);
}

Player::Player()
{
	//switchTime = 0.3;
	this->speed = 100;
	//this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(nullptr);
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		movement.y -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		movement.y += speed;
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}



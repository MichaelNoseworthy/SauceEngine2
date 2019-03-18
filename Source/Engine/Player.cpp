/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "Player.h"


//Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
Player::Player(sf::Texture* Texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight)
{
	switchTime = 0.5;
	this->speed = speed;
	this->jumpHeight = jumpHeight;	
	row = 0;
	faceRight = true;
	body.setSize(sf::Vector2f(30.0f, 90.0f));
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
	canJump = true;
	body.setSize(sf::Vector2f(70.0f, 105.0f));
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
	velocity.x *= 0.0f; //stp whe nno pressed

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		velocity.y -= speed*deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		velocity.y += speed*deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		velocity.y = -sqrt(2.0f * 98.1f * jumpHeight);
	}

	if (useGravity == true)
	velocity.y += 98.1f * deltaTime;

	body.move(velocity * deltaTime);
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision under
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}



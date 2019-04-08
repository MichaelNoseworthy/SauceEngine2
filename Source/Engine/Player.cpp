/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "Player.h"


//Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
Player::Player(sf::Texture* Texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight) : animation(Texture, imageCount, switchTime)
{
	switchTime = 0.5;
	this->speed = speed;
	this->jumpHeight = jumpHeight;	
	row = 0;
	faceRight = true;
	sf::Vector2u TextureSize = Texture->getSize();
	TextureSize.x / 3; //now being used
	body.setSize(sf::Vector2f(20.0f, 32.0f));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(206.0f, 206.0f);
	body.setTexture(Texture);
}

Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	//sf::Vector2f movement(0.0f, 0.0f);
	velocity.x *= 0.0f; //stp whe nno pressed

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		row = 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canJump)
		row = 2;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;		
		velocity.y = -sqrt(2.0f * 98.1f * jumpHeight);
	}

	if (velocity.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	if (velocity.y > 0.0f && !canJump)
	{
		row = 3;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	if (useGravity == true)
	velocity.y += 98.1f * deltaTime;

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
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




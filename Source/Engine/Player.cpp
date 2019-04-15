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
	transComp.speed = speed;
	transComp.jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;
	sf::Vector2u TextureSize = Texture->getSize();
	TextureSize.x / 3; //now being used
	
	transComp.body.setTexture(Texture);
}

Player::~Player()
{

}

void Player::Update (float deltaTime, sf::Texture* texture)
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		row = 4;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && canJump)
		row = 2;

	
	if (transComp.position.y > 0.0f && !transComp.canJump)
	{
		if (transComp.position.x == 0.0f)
		{
			row = 3;
		}
		else {
			row = 3;
			if (transComp.position.x > 0.0f)
				faceRight = true;
			else
				faceRight = false;
		}
	}

	if (transComp.position.x == 0.0f)
	{
		row = 0;
	}
	else
	{
		row = 1;
		if (transComp.position.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}



	animation.Update(row, deltaTime, faceRight);
	transComp.body.setTextureRect(animation.uvRect);
}

void Player::Draw(sf::RenderWindow & window)
{
	window.draw(transComp.body);
}

void Player::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		transComp.position.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		transComp.position.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision under
		transComp.position.y = 0.0f;
		canJump = true;		
	}
	else if (direction.y > 0.0f)
	{
		transComp.position.y = 0.0f;
	}
}




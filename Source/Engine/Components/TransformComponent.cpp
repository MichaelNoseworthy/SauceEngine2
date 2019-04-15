/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "TransformComponent.h"

TransformComponent::TransformComponent()
{
	/*this->speed = 50;
	this->jumpHeight = 70;*/
	body.setPosition(206.0f, 206.0f);
	body.setSize(sf::Vector2f(20.0f, 32.0f));
	body.setOrigin(body.getSize() / 2.0f);
}

void TransformComponent::Awake()
{
}

void TransformComponent::Start()
{

}

void TransformComponent::Update(float time) {

	position.x *= 0.0f;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;
		position.y = -sqrt(2.0f * 98.1f * jumpHeight);
	}

	if (useGravity == true)
		position.y += 98.1f * time;

	body.move(position * time);
}

void TransformComponent::FixedUpdate() {

}
void TransformComponent::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		position.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		position.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision under
		position.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		position.y = 0.0f;
	}
}